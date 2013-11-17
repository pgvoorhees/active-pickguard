
/* OSBDM-JM60 Target Interface Software Package
 * Copyright (C) 2009  Freescale
 *
 * This software package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */



/*****************************************************************************\
*
*	Author:		Axiom Manufacturing
*
*	File:		bdm_9S08.c
*
*	Purpose: 	BDM 9S08 command formatter file
*				Contains commands specific to BGND devices
*				Supports 9S08 processors
*
*	History:	August 2008, Initial Development
*
*
* 03/08/2011  : Modified by P&E Microcomputer Systems
*               http://www.pemicro.com/osbdm
*
*
\*****************************************************************************/ 

#include "derivative.h"				// Include peripheral declarations  
#include "typedef.h"				// Include peripheral declarations  
#include "MCU.h"					// MCU header
#include "timer.h"					// timer functions
#include "targetAPI.h"				// target API include file
#include "bdm_9S08.h"				// BDM include file
#include "bdm_bgnd_driver.h"		// The driver interface
#include "board_id.h"		  // Board ID

//---------------------------------------------------------------------------
// Firmware Info
//---------------------------------------------------------------------------

volatile const byte TARGET_TYPE  =  eS08;
volatile const byte FIRMWARE_TYPE  =  eGeneric;

//---------------------------------------------------------------------------
// Internal definitions and variables
//---------------------------------------------------------------------------

static byte txBuff [8];				// Buffer for write bytes of BGND protocol
static byte rxBuff [8];				// Buffer for read  bytes of BGND protocol

byte   EnableBDM (void);			// Function to enable BDM mode

//---------------------------------------------------------------------------
//	Sync state machine definitions
//---------------------------------------------------------------------------

typedef enum
	{
	SyncReset = 0,	// Called when explicitly syncing, no future sync request
	SyncIfNeeded,	// Sync if needed; no future sync request
	SyncNow,		// Sync now; no future sync request
	SyncNext,		// Sync if needed; sync on next SyncIfNeeded request
	} SyncRequest;

//---------------------------------------------------------------------------
//	Data access macros - currently designed to swap bytes for Intel host
//---------------------------------------------------------------------------

#define GetDataByte32(pData, index) (pData[3 - index])
#define GetDataByte16(pData, index) (pData[1 - index])

//---------------------------------------------------------------------------
// BDM command codes
//---------------------------------------------------------------------------

#define CMDBDM_ACKENB      0xD5 //  d
#define CMDBDM_ACKDSB      0xD6 //  d
#define CMDBDM_BGND        0x90 //  d

#define CMDBDM_READSTAT    0xE4 //  SS
#define CMDBDM_WRITECNTL   0xC4 //  CC

#define CMDBDM_READ8       0xE0 //  A16/d/R8
#define CMDBDM_READ8SS     0xE1 //  A16/d/SS/R8
#define CMDBDM_READLAST    0xE8 //  SS/RD

#define CMDBDM_WRITE8      0xC0 //  A16/W8/d
#define CMDBDM_WRITE8SS    0xC1 //  A16/W8/d/SS

#define CMDBDM_READBKPT    0xE2 //  RBKPT
#define CMDBDM_WRITEBKPT   0xC2 //  WBKPT

#define CMDBDM_GO          0x08 //  d
#define CMDBDM_TRACE1      0x10 //  d
#define CMDBDM_TAGGO       0x18 //  d

#define CMDBDM_READA       0x68 //  d/R8
#define CMDBDM_READCCR     0x69 //  d/R8
#define CMDBDM_READPC      0x6B //  d/R16
#define CMDBDM_READHX      0x6C //  d/R16
#define CMDBDM_READSP      0x6F //  d/R16

#define CMDBDM_READNEXT    0x70 //  d/R8
#define CMDBDM_READNEXTSS  0x71 //  d/SS/R8

#define CMDBDM_WRITEA      0x48 //  W8/d
#define CMDBDM_WRITECCR    0x49 //  W8/d
#define CMDBDM_WRITEPC     0x4B //  W16/d
#define CMDBDM_WRITEHX     0x4C //  W16/d
#define CMDBDM_WRITESP     0x4F //  W16/d

#define CMDBDM_WRITENEXT   0x50 //  W8/d
#define CMDBDM_WRITENEXTSS 0x51 //  W8/d/SS

//----------------------------------------------------------------------------
// Enumerators for the debug registers
//----------------------------------------------------------------------------

enum
	{
	BDCSCR_ENBDM  = 0x80, // R/W
	BDCSCR_BDMACT = 0x40, // RONLY
	BDCSCR_BKPTEN = 0x20, // R/W
	BDCSCR_FTS    = 0x10, // R/W
	BDCSCR_CLKSW  = 0x08, // R/W
	BDCSCR_WS     = 0x04, // RONLY
	BDCSCR_WSF    = 0x02, // RONLY
	BDCSCR_DVF    = 0x01  // RONLY
	};

enum	// Debug register indices
	{
	DEBUG_BDCSCR  = 0x00,
	DEBUG_BDCBKPT = 0x01
	};

//---------------------------------------------------------------------------
//	Sync manager state machine (internal use only)
//---------------------------------------------------------------------------
	void
SyncCheck (
	SyncRequest  request)			// Requested sync machine action

	{
static byte  synconcheck = FALSE;	// TRUE if requesting a future sync

	switch (request)
        {
        case SyncReset:
			synconcheck = FALSE;
            break;

        case SyncIfNeeded:
			if (synconcheck)
				(void) t_sync();
			synconcheck = FALSE;
            break;

        case SyncNow:
			(void) t_sync();
			synconcheck = FALSE;
            break;

        case SyncNext:
			if (synconcheck)
				(void) t_sync();
			synconcheck = TRUE;
			break;
        }
	}

//---------------------------------------------------------------------------
//	Check target power status and enable Vout if target not self-powered,
//  enable and initialize BDM signals to target, issue reset to target
//---------------------------------------------------------------------------
	byte				// Returns 0 for success, 1 for failure
t_init (void)
	{
	BgndInit();						// Initialize the BGND driver

	if (bdm_vtrg_en())				// Enable Vout to target if not self-powered
		return (1);					// Failed, return error
	wait_ms(10);

  if (EnableBDM())      // Enable BDM
    return (1);	
  
	return (0);						// Return success
	}


void t_debug_init()
{

}

void t_serial_init()
{

}

//---------------------------------------------------------------------------
//	Assert reset to target device
//---------------------------------------------------------------------------
	byte				// Returns 0 for success
t_reset (
	ResetT  mode)	// Mode:  0 soft reset to BDM mode, 
	              //      1 hard reset to Running mode, 
	              //      2 hard reset to BDM mode, 
	              //      3 voltage reset to BDM mode (bdm must supply power)
	              //			4 soft reset to Running mode
	{
		 		
	byte  cmd;
	byte  status = 0;		// Returned status

	SyncCheck(SyncReset);
	SyncCheck(SyncNext);
	
  switch(mode){
    case eSoftReset_to_DebugMode: // Soft Reset to BDM mode
			cmd = 0x01;	// Soft reset command
			status = (byte) t_soft_reset_halt(0,0x1801,8,1,&cmd);	// Issue the soft reset command
		  wait_ms(20);							// Allow the reset to complete

			// just in case the halt failed on this target...
			status += t_halt();			// Enable BDM and Halt target		  
      break;

    case eHardReset_to_NormalMode:  
      status = BgndReset(1);  // hard reset to normal (running) mode
      break;

    case eHardReset_to_DebugMode:
      status = BgndReset(0);  // hard reset to BDM (halted) mode
      break;

    case ePowerReset_to_DebugMode:
      status = BgndReset(2);  // voltage reset to BDM (halted) mode
      break;

    case eSoftReset_to_NormalMode:
    default:
			cmd = 0x01;	// Soft reset command
			status = (byte) t_write_mem(0,0x1801,8,1,&cmd);	// Issue the soft reset command
		  wait_ms(20);							// Allow the reset to complete

			status += EnableBDM();		// Initialize cumulative status
			SyncCheck(SyncNow);

			// just in case the go failed on this target
			status += t_go();			// enter normal (running) mode
      break;
  }
	return status;
}

//---------------------------------------------------------------------------
//	Write soft reset command with BDM line set for halt after
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_soft_reset_halt (
	
	byte     type,		// Memory type (ignored)
	UINT32   addr,		// Target memory starting write address
	UINT8    width,		// Object width (8/16/32)
	int      count,		// Total number of BYTEs
	PUINT8  pData)		// Ptr to Little-Endian origination data

	{

	SyncCheck(SyncIfNeeded);

	txBuff[0] = CMDBDM_WRITE8;
	txBuff[1] = (addr >> 8) & 0xFF;	// Addr MSB first
	txBuff[2] = (addr     ) & 0xFF;	// Only 16 bits used
	txBuff[3] = pData[0];
	if (BgndTxRx(txBuff, NULL, 4, 0x80) != 0)
		return (1);
	return (0);
	}



//---------------------------------------------------------------------------
//	Perform a sync operation on the target
//---------------------------------------------------------------------------
	word			// Returns the sync interval in 60 MHz. clocks, or 0 for timeout
t_sync (void)

	{
	SyncCheck(SyncReset);		// Reset the sync state machine
	return (BgndSync());		// Sync the target
	}

//---------------------------------------------------------------------------
//	Resynchronize host and target if comm is disrupted
//---------------------------------------------------------------------------
	byte				// Returns 0 for success, 1 for failure
t_resync (void)

	{
	return (t_sync() == 0);
	}

//---------------------------------------------------------------------------
//	Get the current BDM clock value of the target
//---------------------------------------------------------------------------
	UINT32
t_get_clock (void)

	{
  SyncCheck(SyncNow);
	return (UINT32)(BgndGetClock());
	}

	int t_special_feature(unsigned char sub_cmd_num,  // Special feature number (sub_cmd_num)
	                     PUINT16 pInputLength,      // Length of Input Command
	                     PUINT8  pInputBuffer,               // Input Command Buffer
	                     PUINT16 pOutputLength,     // Length of Output Response
	                     PUINT8  pOutputBuffer)    {          // Output Response Buffer 
int i;

UINT8  temp_cmd;
UINT32 hold_address;
hold_address = 0;
*pOutputLength = 0;

switch (sub_cmd_num)
        {
        case 0xAA:
          //for (i=1;i<=*pInputLength;i++) 
          //  pOutputBuffer[i-1] = pInputBuffer[i-1] ^ 0xff;
          //*pOutputLength = *pInputLength;
          *pOutputLength = 0;
          return (0) ; //success
          break;
        case 0x01: // send sync request
          SyncCheck(SyncNow); // allow PC to sync to the part
          *pOutputLength = 0;
          //wait_ms(25);
          return (0) ; // success
          break;

        case 0x07: // Set BKGD low if pInputBuffer[0] = 0, high-z if pInputBuffer[0] = FF
          if (pInputBuffer[0] == 0xff) 
          {
            BgndHiz();  
          }
          if (pInputBuffer[0] == 0x00) 
          {
            BgndLow();
          }
          *pOutputLength = 0; 
          return (0);
          break;
        case 0x08:
          if (pInputBuffer[0] == 0xff) 
          {  
            ResetHiz();
          }
          if (pInputBuffer[0] == 0x00) 
          {
            ResetLow(); 
          }
          *pOutputLength = 0;
          return (0);
          break;
           
            
            

        case 0x1D: 
          //for (i=1;i<=*pInputLength;i++) 
          //  {
          //  pOutputBuffer[i-1] = pInputBuffer[i-1] ^ 0xff;
          //  }
          *pOutputLength = 0;
          for (i=0; i<*pInputLength-1; i++)
          {
            temp_cmd = *pInputBuffer++;
            switch(temp_cmd) 
            {
              case 0x00:
              i++;
              BgndTxRx(pInputBuffer++, NULL, 1, 0);
              BgndDelay();
              break;
              
              case 0x07:
              i++;
              pInputBuffer++;
              BgndTxRx(NULL, rxBuff, 0, 1);
              pOutputBuffer[*pOutputLength]=rxBuff[0];
              (*pOutputLength)++;
              BgndDelay();
              break;

              default:
                i++;
                pInputBuffer++;
              break;
                
            }
              
          }
          return (0);
          break;
          
        case 0x13: /* soft reset and keep bkgd line low */
          t_reset(eSoftReset_to_DebugMode);
          *pOutputLength = 0;
          return (0);
          break;
        case 0x20: /* turn off power to target */
          VTRG_EN = 0;
          *pOutputLength = 0;
          return (0);
          break;
        case 0x21: /* turn on power to target */
          VTRG_EN = 1;
          *pOutputLength = 0;
          return (0);
          break; 
        }
return (1); // failure
}

//---------------------------------------------------------------------------
//	Set the BDM clock value of the target
//---------------------------------------------------------------------------
	void
t_set_clock (
	UINT32 clock)

	{
	SyncCheck(SyncReset);			// Reset the sync state machine
	BgndSetClock((UINT16)(clock));	// Will also sync to the target
	}

//---------------------------------------------------------------------------
//	Enable/disable the programming voltage power supply
//---------------------------------------------------------------------------
	int
t_flash_power (
	byte enable)		// 1 to enable, 0 to disable

	{
	return (0);			// Not used for 9S08 targets
	}

//---------------------------------------------------------------------------
//	Enable/disable the programming voltage to the target chip
//---------------------------------------------------------------------------
	int
t_flash_enable (
	byte enable)		// 1 to enable, 0 to disable

	{
	return (0);			// Not used for 9S08 targets
	}

//---------------------------------------------------------------------------
//	Execute flash programming algo
//---------------------------------------------------------------------------
	int
t_flash_prog (
	PUINT8  pData)	// ptr to data buffer

	{
	return (0);			// Not used for 9S08 targets
	}


//---------------------------------------------------------------------------
//	Enable/disable the target ACK protocol
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_enable_ack (
	byte  enable)		// 1 to enable, 0 to disable

	{
	byte  status;		// Returned status

	if ( ! BgndAckSupported())
		return (enable != 0);	// The driver does not support ACK

	SyncCheck(SyncIfNeeded);

	txBuff[0] = ((enable) ? CMDBDM_ACKENB : CMDBDM_ACKDSB);
	status    = BgndTxRx(txBuff, NULL, 1, 0);

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Get the current state of the PST inputs
//---------------------------------------------------------------------------
	byte				// Returns the current PST state
bdmcf_pst_status (void)

	{
	// Not required for a BDM connection (signals not used), but required to link
	return (0);
	}

//---------------------------------------------------------------------------
//	Asserts TA to target for user delay in 10us increments
//---------------------------------------------------------------------------
	void
t_assert_ta (
	word dly_cnt)

	{
	// Not required for a BDM connection (signal not used), but required to link
	}

//---------------------------------------------------------------------------
//	Mass erase and unsecure target FLASH.
//	Wait_ms() provides delay to allow FLASH erase to complete before exit
//---------------------------------------------------------------------------
#pragma MESSAGE DISABLE C5703
	char
t_unsecure (
	byte lockr,
	byte lrcnt,
	byte clkdiv)

	{
	BgndUnsecure();	// (Not implemented)
	wait_ms(1);
	return 0;
	}
#pragma MESSAGE DEFAULT C5703

//---------------------------------------------------------------------------
//	Write a control register (unsupported for 9S08)
//---------------------------------------------------------------------------
#pragma MESSAGE DISABLE C5703
	int					// Returns 0 for success, 1 for failure
t_write_creg (
	UINT32   addr,		// Register number
	PUINT8  pData)		// Ptr to value buffer

	{
	return (1);			// Return error for unsupported
	}
#pragma MESSAGE DEFAULT C5703

//---------------------------------------------------------------------------
//	Read control register (unsupported for 9S08)
//---------------------------------------------------------------------------
#pragma MESSAGE DISABLE C5703
	int					// Returns 0 for success, 1 for failure
t_read_creg (
	UINT32   addr,		// Register number
	PUINT8  pData)		// Ptr to return buffer

	{
	return (1);			// Return error for unsupported
	}
#pragma MESSAGE DEFAULT C5703

//---------------------------------------------------------------------------
//	Write Debug Register
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_write_dreg (
	UINT32   addr,		// Register number
	UINT8    uWidth,	// Register width (ignored)
	PUINT8  pData)		// Ptr to value buffer

	{
	int      status;	// The returned status

	SyncCheck(SyncIfNeeded);

	if (addr == 0)
		{
		txBuff[0] = CMDBDM_WRITECNTL;	// Write BDCSCR
		txBuff[1] = pData[0];
		status    = BgndTxRx(txBuff, NULL, 2, 0);
		}
	else if (addr == 1)
		{
		txBuff[0] = CMDBDM_WRITEBKPT;	// Write BDCBKPT
		txBuff[1] = GetDataByte16(pData, 0);
		txBuff[2] = GetDataByte16(pData, 1);
		status    = BgndTxRx(txBuff, NULL, 3, 0);
		}
	else
		status = 1;

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Read Debug Register
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_read_dreg (
	UINT32   addr,		// Register number
	UINT8    uWidth,	// Register width (ignored)
	PUINT8  pData)		// Ptr to return buffer

	{
	int      status;	// The returned status

  SyncCheck(SyncIfNeeded);

	pData[0] = 0;		// Preclear the return buffer
	pData[1] = 0;
	pData[2] = 0;
	pData[3] = 0;

	if (addr == 0)
		{
		txBuff[0] = CMDBDM_READSTAT;	// Read BDCSCR
		status    = BgndTxRx(txBuff, rxBuff, 1, 1);
		pData[0]  = rxBuff[0];
		}
	else if (addr == 1)
		{
		txBuff[0] = CMDBDM_READBKPT;	// Read BDCBKPT
		status    = BgndTxRx(txBuff, rxBuff, 1, 2);
		pData[0]  = GetDataByte16(rxBuff, 0);
		pData[1]  = GetDataByte16(rxBuff, 1);
		}
	else
		status = 1;

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Write a CPU register
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_write_ad (
	UINT32    addr,		// Register number: [0:4]
	PUINT8  pData)		// Ptr to Little Endian register value

	{
	int      status;	// The returned status

  SyncCheck(SyncIfNeeded);

  addr = 0x000000FF & addr;

	switch (addr)
        {
        case BGNDREG_A:
			txBuff[0] = CMDBDM_WRITEA;
			txBuff[1] = pData[0];
			status    = BgndTxRx(txBuff, NULL, 2, 0);
            break;

        case BGNDREG_CCR:
			txBuff[0] = CMDBDM_WRITECCR;
			txBuff[1] = pData[0];
			status    = BgndTxRx(txBuff, NULL, 2, 0);
            break;

        case BGNDREG_HX:
			txBuff[0] = CMDBDM_WRITEHX;
			txBuff[1] = GetDataByte16(pData, 0);
			txBuff[2] = GetDataByte16(pData, 1);
			status    = BgndTxRx(txBuff, NULL, 3, 0);
            break;

        case BGNDREG_SP:
			txBuff[0] = CMDBDM_WRITESP;
			txBuff[1] = GetDataByte16(pData, 0);
			txBuff[2] = GetDataByte16(pData, 1);
			status    = BgndTxRx(txBuff, NULL, 3, 0);
            break;

        case BGNDREG_PC :
			txBuff[0] = CMDBDM_WRITEPC;
			txBuff[1] = GetDataByte16(pData, 0);
			txBuff[2] = GetDataByte16(pData, 1);
			status    = BgndTxRx(txBuff, NULL, 3, 0);
            break;

		default:
			status = 1;	// Report error
			break;
        }

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Read a CPU register
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_read_ad (
	UINT32    addr,		// Register number: [0:4]
	PUINT8  pData)		// Ptr to Little Endian register value

	{
	int      status;	// The returned status

	addr = 0x000000FF & addr;

  SyncCheck(SyncIfNeeded);

	pData[0] = 0;		// Preclear
	pData[1] = 0;
	pData[2] = 0;
	pData[3] = 0;
	switch (addr)
        {
        case BGNDREG_A:
			txBuff[0] = CMDBDM_READA;
			status    = BgndTxRx(txBuff, rxBuff, 1, 1);
			pData[0]  = rxBuff[0];
            break;

        case BGNDREG_CCR:
			txBuff[0] = CMDBDM_READCCR;
			status    = BgndTxRx(txBuff, rxBuff, 1, 1);
			pData[0]  = rxBuff[0];
            break;

        case BGNDREG_HX:
			txBuff[0] = CMDBDM_READHX;
			status    = BgndTxRx(txBuff, rxBuff, 1, 2);
			pData[0]  = GetDataByte16(rxBuff, 0);
			pData[1]  = GetDataByte16(rxBuff, 1);
            break;

        case BGNDREG_SP:
			txBuff[0] = CMDBDM_READSP;
			status    = BgndTxRx(txBuff, rxBuff, 1, 2);
			pData[0]  = GetDataByte16(rxBuff, 0);
			pData[1]  = GetDataByte16(rxBuff, 1);
            break;

        case BGNDREG_PC :
			txBuff[0] = CMDBDM_READPC;
			status    = BgndTxRx(txBuff, rxBuff, 1, 2);
			pData[0]  = GetDataByte16(rxBuff, 0);
			pData[1]  = GetDataByte16(rxBuff, 1);
            break;

		default:
			status = 1;	// Report error
			break;
        }

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Write data to target memory
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_write_mem (
	byte     type,		// Memory type (ignored)
	UINT32   addr,		// Target memory starting write address
	UINT8    width,		// Object width (8/16/32)
	int      count,		// Total number of BYTEs
	PUINT8  pData)		// Ptr to Little-Endian origination data

	{
	byte index;			// Byte loop counter

	if (count <= 0)		// Error if invalid request length
		return (1);

	SyncCheck(SyncIfNeeded);

	txBuff[0] = CMDBDM_WRITE8;
	if (width == 8)
        {
		while (count >= 1)		// 8-bit writes
			{
			txBuff[1] = (addr >> 8) & 0xFF;	// Addr MSB first
			txBuff[2] = (addr     ) & 0xFF;	// Only 16 bits used
			txBuff[3] = pData[0];
			if (BgndTxRx(txBuff, NULL, 4, 0) != 0)
				return (1);
			++addr;
			pData += 1;
			count -= 1;
			}
		}

	else if (width == 16)
		{
		while (count >= 2)		// 16-bit writes
			{
			for (index = 0; (index < 2); ++index)
				{
				txBuff[1] = (addr >> 8) & 0xFF;
				txBuff[2] = (addr     ) & 0xFF;
				txBuff[3] = GetDataByte16(pData, index);
				if (BgndTxRx(txBuff, NULL, 4, 0) != 0)
					return (1);
				++addr;
				}
			pData += 2;
			count -= 2;
			}
		}

	else /* (width == 32) */
		{
		while (count >= 4)		// 32-bit writes
			{
			for (index = 0; (index < 4); ++index)
				{
				txBuff[1] = (addr >> 8) & 0xFF;
				txBuff[2] = (addr     ) & 0xFF;
				txBuff[3] = GetDataByte32(pData, index);
				if (BgndTxRx(txBuff, NULL, 4, 0) != 0)
					return (1);
				++addr;
				}
			pData += 4;
			count -= 4;
			}
		}

	return (0);
	}

//---------------------------------------------------------------------------
//	Read data from the target memory
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_read_mem (
	byte     type,		// Memory type (ignored)
	UINT32   addr,		// Target memory starting read address
	UINT8    width,		// Object width (8/16/32)
	int      count,		// Total number of BYTEs
	PUINT8  pData)		// Ptr to Little-Endian destination buffer

	{
	byte index;			// Byte loop counter

	if (count <= 0)		// Error if invalid request length
		return (1);

	SyncCheck(SyncIfNeeded);

	txBuff[0] = CMDBDM_READ8;
	if (width == 8)
        {
		while (count >= 1)		// 8-bit reads
			{
			txBuff[1] = (addr >> 8) & 0xFF;	// Addr MSB first
			txBuff[2] = (addr     ) & 0xFF;	// only 16 bits used
			if (BgndTxRx(txBuff, &rxBuff[0], 3, 1) != 0)
				return (1);
			++addr;
			*pData++ = rxBuff[0];
			count   -= 1;
			}
		}

	else if (width == 16)
		{
		while (count >= 2)		// 16-bit reads
			{
			for (index = 0; (index < 2); ++index)
				{
				txBuff[1] = (addr >> 8) & 0xFF;
				txBuff[2] = (addr     ) & 0xFF;
				if (BgndTxRx(txBuff, &rxBuff[index], 3, 1) != 0)
					return (1);
				++addr;
				}
			*pData++ = GetDataByte16(rxBuff, 0);
			*pData++ = GetDataByte16(rxBuff, 1);
			count   -= 2;
			}
		}

	else /* (width == 32) */
		{
		while (count >= 4)		// 32-bit reads
			{
			for (index = 0; (index < 4); ++index)
				{
				txBuff[1] = (addr >> 8) & 0xFF;
				txBuff[2] = (addr     ) & 0xFF;
				if (BgndTxRx(txBuff, &rxBuff[index], 3, 1) != 0)
					return (1);
				++addr;
				}
			*pData++ = GetDataByte32(rxBuff, 0);
			*pData++ = GetDataByte32(rxBuff, 1);
			*pData++ = GetDataByte32(rxBuff, 2);
			*pData++ = GetDataByte32(rxBuff, 3);
			count   -= 4;
			}
		}

	return (0);
	}

//---------------------------------------------------------------------------
//	Fill target memory with data
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_fill_mem (
	byte     type,		// Memory type (ignored)
	UINT32   addr,		// Target memory starting write address
	UINT8    width,		// Object width (8/16/32)
	int      count,		// Total number of 8/16/32 bit OBJECTs
	PUINT8  pData)		// Ptr to Little-Endian 8/16/32 bit fill object

	{
	int      size;		// Number bytes per write	

	if (count <= 0)		// Error if invalid request length
		return (1);

 	if      (width ==  8)
		size = 1;
	else if (width == 16)
		size = 2;
	else /* (width == 32) */
		size = 4;

	while (count-- > 0)
		{
		if (t_write_mem(type, addr, width, size, pData) != 0)
			return (1);
		addr += size;
		}

	return (0);
	}

//---------------------------------------------------------------------------
//	Enable BDM processing
//---------------------------------------------------------------------------
	byte				// Returns 0 for success, 1 for failure
EnableBDM (void)

	{
	byte  status;		// Returned status

	SyncCheck(SyncNow);

	txBuff[0] = CMDBDM_READSTAT;
	status    = BgndTxRx(txBuff, &txBuff[1], 1, 1);
	if ((txBuff[1] & BDCSCR_ENBDM) == 0)	// Is BDM enabled?
		{
		txBuff[1] |= BDCSCR_ENBDM;			// No, enable it
		txBuff[0]  = CMDBDM_WRITECNTL;		// and write it back
		status    |= BgndTxRx(txBuff, NULL, 2, 0);
		}
	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Halt target execution
//---------------------------------------------------------------------------
	byte				// Returns 0 for success, 1 for failure
t_halt (void)

	{
	byte  status = EnableBDM();		// Initialize cumulative status

	wait_ms(1);								// Wait for it to happen

	txBuff[0] = CMDBDM_BGND;				// Issue the HALT command
	status   |= BgndTxRx(txBuff, NULL, 1, 0);

	wait_ms(1);								// Wait for it to happen

	txBuff[0] = CMDBDM_READSTAT;			// Check if succeeded
	status   |= BgndTxRx(txBuff, rxBuff, 1, 1);
	if ((rxBuff[0] & BDCSCR_BDMACT) == 0)
		status = 1;							// Did not halt

	return (status != 0);
	}

 
//---------------------------------------------------------------------------
//    Resume target execution from the current PC
//---------------------------------------------------------------------------
    byte                // Returns 0 for success, 1 for failure
t_go (void)

    {
    byte  status;        // Cumulative status

    SyncCheck(SyncNow);

    txBuff[0] = CMDBDM_GO;                    // Issue the GO command
    status    = BgndTxRx(txBuff, NULL, 1, 0);

    wait_ms(1);                                // Wait for it to happen

    // sometimes, after a go, BDCSCR_ENBDM is clear
    (void) EnableBDM();        // enable BDM

    txBuff[0] = CMDBDM_READSTAT;            // Check if succeeded
    status   |= BgndTxRx(txBuff, rxBuff, 1, 1);

    if ((rxBuff[0] & BDCSCR_BDMACT) != 0)
        status = 1;                            // Did not start
    return (status != 0);
    }


//---------------------------------------------------------------------------
//	Execute one instruction from the current PC
//---------------------------------------------------------------------------
	byte				// Returns 0 for success, 1 for failure
t_step (void)

	{
	byte  status;		// Cumulative status

	SyncCheck(SyncNext);

	txBuff[0] = CMDBDM_TRACE1;				// Issue the STEP command
	status    = BgndTxRx(txBuff, NULL, 1, 0);

	return (status != 0);
	}

//---------------------------------------------------------------------------
//	Return the bdm/target status information to host
//	
//	pData[] will be loaded with bytes as follows:
//		0    = ACK support (No = 0,  Yes = 1) (8b)
//		1    = Target reset detect (No = 0, Yes = 1)  (8b)
//		2    = Target detection state (NONE = 0, SYNC = 1, Manual = 3) (8b)
//		3..9 = unused
//---------------------------------------------------------------------------
	int					// Returns 0 for success, 1 for failure
t_stat (
	PUINT8  pData)		// Ptr to return status buffer

{
   	SyncCheck(SyncIfNeeded);
  	pData[0] = BgndAckSupported();
//	pData[1] = BgndResetDetect();
  	pData[1] = 0;	// disable reset detect reporting because the rsti pin is muxed on some s08's
  	pData[2] = BgndClockState();
    pData[3] = VERSION_HW;	// Hardware Version
    pData[4] = VERSION_SW;	// Firmware Version
    pData[5] =
  	pData[6] =
  	pData[7] =
  	pData[8] =
  	pData[9] =  0;


	return (0);
}

//---------------------------------------------------------------------------
//	Return the bdm/target status information to host
//	
//	pData[] will be loaded with bytes as follows:
//		0    = VERSION_HW
//		1    = VERSION_SW
//		2    = BUILD_VER
//		3    = TARGET_TYPE
//    4    = FIRMWARE_TYPE
//		5    = BUILD_VER_REV
//    6    = board_id
//    7    = osbdm_id
//    8..9 = unused
//---------------------------------------------------------------------------

int					// Returns 0 for success, 1 for failure
t_get_ver (
	PUINT8  pData)		// Ptr to return status buffer

{
    pData[0] = VERSION_HW;	// Hardware Version
    pData[1] = VERSION_SW;	// Firmware Version
    pData[2] = BUILD_VER;
  	pData[3] = TARGET_TYPE;
  	pData[4] = FIRMWARE_TYPE;
  	pData[5] = BUILD_VER_REV;
  	pData[6] = board_id; 
  	pData[7] = osbdm_id;
  	pData[8] = 0;
  	pData[9] =  0;

 	return (0);
}

//---------------------------------------------------------------------------
//	Configure parameters 
//---------------------------------------------------------------------------
int t_config (byte configType, byte configParam, UINT32 paramVal)
{
 	return (0);			// Not used for S08 targets			
}


//---------------------------------- EOF ------------------------------------
