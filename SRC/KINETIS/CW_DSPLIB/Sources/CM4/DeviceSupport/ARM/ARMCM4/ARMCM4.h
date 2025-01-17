/**************************************************************************//**
 * @file     ARMCM4.h
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File
 *           for CM4 Device Series
 * @version  V1.03
 * @date     24. September 2010
 *
 * @note
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __ARMCM4_H__
#define __ARMCM4_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!<  2 Cortex-M4 Non Maskable Interrupt                  */
  HardFault_IRQn              = -13,    /*!<  3 Cortex-M4 Hard Fault Interrupt                    */
  MemoryManagement_IRQn       = -12,    /*!<  4 Cortex-M4 Memory Management Interrupt             */
  BusFault_IRQn               = -11,    /*!<  5 Cortex-M4 Bus Fault Interrupt                     */
  UsageFault_IRQn             = -10,    /*!<  6 Cortex-M4 Usage Fault Interrupt                   */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                   */

/******  ARMCM4 specific Interrupt Numbers ********************************************************/
  GPIO_IRQn                   = 0       /*!< GPIO Interrupt                                       */
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __FPU_PRESENT             1         /*!< FPU present or not                               */


#include "core_cm4.h"                       /* Cortex-M4 processor and core peripherals           */
#include "system_ARMCM4.h"                  /* System Header                                      */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/*--------------------- General Purpose Input and Ouptut ---------------------*/
typedef union
{
//  __IO uint32_t WORD;  
//  __IO uint8_t  BYTE[4];
	volatile uint32_t WORD;  
	volatile uint8_t  BYTE[4];
} GPIO_Data_TypeDef;

typedef struct
{
  GPIO_Data_TypeDef DATA [256];
  volatile uint32_t  DIR;
//  __O uint32_t  DIR;
  uint32_t      RESERVED[3];
  volatile uint32_t  IE;
//  __O uint32_t  IE;
} GPIO_TypeDef;


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address */
#define SRAM_BASE             ((     uint32_t)0x20000000UL)
#define PERIPH_BASE           ((     uint32_t)0x40000000UL)

/* Peripheral memory map */
#define GPIO_BASE	          PERIPH_BASE

#define GPIO0_BASE	          (GPIO_BASE)
#define GPIO1_BASE	          (GPIO_BASE       + 0x0800UL)
#define GPIO2_BASE	          (GPIO_BASE       + 0x1000UL)


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define GPIO0		          ((GPIO_TypeDef *) GPIO0_BASE)
#define GPIO1		          ((GPIO_TypeDef *) GPIO1_BASE)
#define GPIO2		          ((GPIO_TypeDef *) GPIO2_BASE)


#endif  /* __ARMCM4_H__ */
