/*                                                                                           
*  Touch Sensing Library System Setup File                                                   
*                                                                                            
*  Auto-generated by System Setup Creator Tool                                               
*                                                                                            
*  This file contains electrode and other Touch Sensing System setup parameters              
*/                                                                                           

#ifndef __TSS_SYSTEM_SETUP_H__
#define __TSS_SYSTEM_SETUP_H__



#define TSS_USE_DELTA_LOG                    0        /* Delta Log array support */

#define TSS_USE_SIGNAL_LOG                   0        /* Signal Log array support */

#define TSS_USE_GPIO_STRENGTH                1        /* Electrode GPIO Strength support */

#define TSS_USE_GPIO_SLEW_RATE               1        /* Electrode GPIO Slew Rate support */

#define TSS_USE_IIR_FILTER                   1        /* IIR Filter support */

#define TSS_USE_NOISE_AMPLITUDE_FILTER       0        /* Noise Amplitude Filter function support */

#define TSS_USE_DATA_CORRUPTION_CHECK        0        /* Data Corruption of TSS registers support */

#define TSS_USE_FREEMASTER_GUI               0        /* FreeMASTER GUI support */

#define TSS_ENABLE_DIAGNOSTIC_MESSAGES       0        /* Diagnostic Messages support */

#define TSS_USE_AUTOTRIGGER_SOURCE           TSI0     /* Identifier of the Trigger source device */

#define TSS_USE_LOWPOWER_CONTROL_SOURCE      TSI0     /* Identifier of the Low Power control source device */

#define TSS_ONFAULT_CALLBACK  				TSS_fOnFault


#define TSS_N_ELECTRODES                     12        /* Number of electrodes present in the system */

/* Electrode's GPIOs configuration */


/* Configuration of Electrode measurement method */

#define TSS_E0_TYPE                          TSI0_CH6      /* Electrode measurement method specification */

#define TSS_E1_TYPE                          TSI0_CH7      /* Electrode measurement method specification */

#define TSS_E2_TYPE                          TSI0_CH8      /* Electrode measurement method specification */

#define TSS_E3_TYPE                          TSI0_CH9      /* Electrode measurement method specification */

#define TSS_E4_TYPE                          TSI0_CH10      /* Electrode measurement method specification */

#define TSS_E5_TYPE                          TSI0_CH11      /* Electrode measurement method specification */

#define TSS_E6_TYPE                          TSI0_CH0      /* Electrode measurement method specification */

#define TSS_E7_TYPE                          TSI0_CH5      /* Electrode measurement method specification */

#define TSS_E8_TYPE                          TSI0_CH15      /* Electrode measurement method specification */

#define TSS_E9_TYPE                          TSI0_CH12      /* Electrode measurement method specification */

#define TSS_E10_TYPE                          TSI0_CH13      /* Electrode measurement method specification */

#define TSS_E11_TYPE                          TSI0_CH14      /* Electrode measurement method specification */

/* Electrode's Noise Amplitude Filter Size configuration */

/* Controls configuration */

#define TSS_N_CONTROLS                       7

#define TSS_C0_TYPE                 TSS_CT_ROTARY     /* Control type */
#define TSS_C0_ELECTRODES           6                 /* Number of electrodes in the control */
#define TSS_C0_STRUCTURE            VolumeWheel             /* Name of the C&S struct to create */
#define TSS_C0_CALLBACK             TSS1_VolumeWheel   /* Identifier of the user's callback */

#define TSS_C1_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C1_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C1_STRUCTURE            ToneVolumeSelect             /* Name of the C&S struct to create */
#define TSS_C1_CALLBACK             TSS1_ToneVolumeSelect   /* Identifier of the user's callback */

#define TSS_C2_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C2_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C2_STRUCTURE            Mute             /* Name of the C&S struct to create */
#define TSS_C2_CALLBACK             TSS1_Mute   /* Identifier of the user's callback */

#define TSS_C3_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C3_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C3_STRUCTURE            Delta             /* Name of the C&S struct to create */
#define TSS_C3_CALLBACK             TSS1_Delta   /* Identifier of the user's callback */

#define TSS_C4_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C4_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C4_STRUCTURE            Alpha             /* Name of the C&S struct to create */
#define TSS_C4_CALLBACK             TSS1_Alpha   /* Identifier of the user's callback */

#define TSS_C5_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C5_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C5_STRUCTURE            Beta             /* Name of the C&S struct to create */
#define TSS_C5_CALLBACK             TSS1_Beta   /* Identifier of the user's callback */

#define TSS_C6_TYPE                 TSS_CT_KEYPAD     /* Control type */
#define TSS_C6_ELECTRODES           1                 /* Number of electrodes in the control */
#define TSS_C6_STRUCTURE            Gamma             /* Name of the C&S struct to create */
#define TSS_C6_CALLBACK             TSS1_Gamma   /* Identifier of the user's callback */


/* Timer Specific parameters */

#define TSS_HW_TIMER                         TPM      /* Define the TSS Timer */

#define TSS_SENSOR_PRESCALER                 2        /* Prescaler for all used Timers */
#define TSS_SENSOR_TIMEOUT                 1023        /* Timeout for all used Timers */

/* TSI Specific parameters */

#define TSS_TSI_RESOLUTION                   8        /* Required Bit resolution of the TSI */

/* TSI Auto-calibration Limits */
#define TSS_TSI_SCANC_EXTCHRG_LOW_LIMIT      0        /* Low Limit of External OSC Charge Current register value for TSI autocalibration */
#define TSS_TSI_SCANC_EXTCHRG_HIGH_LIMIT     31       /* High Limit of External OSC Charge Current register value for TSI autocalibration */
#define TSS_TSI_GENCS_PS_LOW_LIMIT           0        /* Low Limit of External OSC Prescaler register value for TSI autocalibration */
#define TSS_TSI_GENCS_PS_HIGH_LIMIT          7        /* High Limit of External OSC Prescaler register value for TSI autocalibration */

/* Active Mode Clock Settings */
#define TSS_TSI_SCANC_AMCLKS                 0        /* Input Active Mode Clock Source ( 0 = BUSclk, 1 = MCGIRCLK, 2 = OSCERCLK, 3 - NA ) */
#define TSS_TSI_SCANC_AMPSC                  0        /* Input Active Mode Clock Prescaler ( 0 = divide 1, 7 = divide 128 ) */
#define TSS_TSI_SCANC_AMCLKDIV               0        /* Input Active Mode Clock Divider ( 0 = divide 1, 1 = divide 2048 ) */

/* Low Power TSI definitions */
#define TSS_TSI_GENCS_LPCLKS                 0        /* Low Power Mode Clock Source ( 0 = LPOCLK, 1 = VLPOSCCLK ) */



#endif /*__TSS_SYSTEM_SETUP_H__*/