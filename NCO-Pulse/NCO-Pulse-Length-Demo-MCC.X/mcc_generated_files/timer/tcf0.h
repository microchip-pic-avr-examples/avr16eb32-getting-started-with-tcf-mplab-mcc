/**
 * TCF0 Generated Driver API Header File
 * 
 * @file tcf0.h
 * 
 * @defgroup tcf0 TCF0
 * 
 * @brief This document contains the API prototypes and data types for the Timer Counter F (TCF0) module.
 *
 * @version TCF0 Driver Version 1.0.0
 */

/*******************************************************************************
Copyright (c) [2023] released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

#ifndef TCF0_H    /* Guards against multiple inclusion */
#define TCF0_H


/**
 * Section: Included files
 */
#include <stdbool.h>
#include <stdint.h>

/**
 * Section: TCF0 Macro definitions
 */

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from us(microseconds) to clock cycles.
 * - The first argument is the output period expressed in microseconds
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in Frequency mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_F_US_TO_CLOCKS(US, F_CLOCK, TCF0_PRESCALER)   (uint32_t)((((float)(F_CLOCK) * (float)(US)) / (2000000.0 * (float)(TCF0_PRESCALER)) + 0.5) - 1)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from ms(milliseconds) to clock cycles.
 * - The first argument is the output period expressed in milliseconds
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in Frequency mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_F_MS_TO_CLOCKS(MS, F_CLOCK, TCF0_PRESCALER)   (uint32_t)((((float)(F_CLOCK) * (float)(MS)) / (2000.0 * (float)(TCF0_PRESCALER)) + 0.5) - 1)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from seconds to clock cycles.
 * - The first argument is the output period expressed in seconds
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in Frequency mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_F_S_TO_CLOCKS(S, F_CLOCK, TCF0_PRESCALER)   (uint32_t)((((float)(F_CLOCK) * (float)(S)) / (2.0 * (float)(TCF0_PRESCALER)) + 0.5) - 1)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from Hz to clock cycles.
 * - The first argument is the output frequency expressed in Hertz
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in Frequency mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_F_HZ_TO_CLOCKS(HZ, F_CLOCK, TCF0_PRESCALER)   (uint32_t)((float)(F_CLOCK) / (2.0 * (HZ) * (TCF0_PRESCALER)) - 1)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from Hz to Numeric Controlled Oscillator (NCO) increment. 
 * - The first argument is the NCO frequency expressed in Hertz
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in NCO Pulse Length mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_NCOPL_HZ_TO_INCREMENT(HZ, F_CLOCK)   (uint32_t)(((float)(HZ) * 16777216.0) / (float)(F_CLOCK) + 0.5)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from Hz to NCO increment. 
 * - The first argument is the NCO frequency expressed in Hertz
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in NCO Fixed Duty Cycle mode to compute the argument for the @c TCF0_CompareSet() function.
 */
#define TCF0_NCOFD_HZ_TO_INCREMENT(HZ, F_CLOCK, TCF0_PRESCALER)   (uint32_t)(((float)(HZ) * 33554432.0 * (TCF0_PRESCALER)) / ((float)(F_CLOCK)) + 0.5)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from Hz to clock cycles.
 * - The first argument is the Pulse-Width Modulation (PWM) frequency expressed in Hertz
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in PWM mode to compute the argument for the @c TCF0_PWM_PeriodSet() function.
 */
#define TCF0_PWM_PER_HZ_TO_CLOCKS(HZ, F_CLOCK, TCF0_PRESCALER)   (uint8_t)((float)(F_CLOCK) / ((float)(TCF0_PRESCALER) * (HZ)) - 1)

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from ms(microseconds) to clock cycles.
 * - The first argument is the PWM period expressed in microseconds
 * - The second argument is the TCF peripheral clock frequency expressed in Hertz
 * - The third argument is the TCF prescaler value as an integer
 * @brief Used in PWM mode to compute the argument for the @c TCF0_PWM_PeriodSet() function.
 */
#define TCF0_PWM_PER_US_TO_CLOCKS(US, F_CLOCK, TCF0_PRESCALER)   (uint8_t)(((float)(F_CLOCK) * (float)(US)) / (1000000.0 * (float)(TCF0_PRESCALER)) + 0.5) - 1

/**
 * @ingroup tcf0
 * @brief
 * Performs the conversion from duty cycle to clock cycles.
 * - The first argument is the duty cycle expressed as a real value between 0.0 and 1.0
 * - The second argument is an integer expressing the period in clock cycles
 * @brief Used in PWM mode to compute arguments for the @c TCF0_PWM_DutyCycle0Set() and @c TCF0_PWM_DutyCycle1Set() functions.
 */
#define TCF0_PWM_DCY_TO_CLOCKS(dcy, PER)   (uint8_t)(float)((dcy) * (PER))

/**
 * Section: TCF0 Custom data types
 */

/**
 * @ingroup tcf0
 * @brief Pointer to a function that gets no arguments and returns. @n Used as a callback function pointer.
 */
typedef void (*TCF0_cb_t)(void);

/**
 * @ingroup tcf0
 * @enum TCF0_status_t
 * @brief Lists the possible states of TCF0:
 * - @c TCF_STATUS_IDLE = 0 @c      -   The timer is not running
 * - @c TCF_STATUS_RUNNING = 1 @c   -   The timer is running
 */
typedef enum
{
    TCF_STATUS_IDLE =       0,          /* The timer is not running*/
    TCF_STATUS_RUNNING =    1,          /* The timer is running */
} TCF0_status_t; 


/**
 * Section: TCF0 Module APIs
 */

/**
 * @ingroup tcf0
 * @brief Setter function for TCF0 overflow callback.
 * @pre None.
 * @param TCF0_cb_t Pointer to custom callback function.
 * @return None.
 */
void TCF0_OverflowCallbackRegister(TCF0_cb_t cb);


/**
 * @ingroup tcf0
 * @brief Setter function for TCF0 Capture-Compare0 callback function.
 * @pre None.
 * @param TCF0_cb_t Pointer to custom callback function.
 * @return None.
 */
void TCF0_Compare0CallbackRegister(TCF0_cb_t cb);


/**
 * @ingroup tcf0
 * @brief Setter function for TCF0 Capture-Compare1 callback function.
 * @pre None.
 * @param TCF0_cb_t Pointer to custom callback function.
 * @return None.
 */
void TCF0_Compare1CallbackRegister(TCF0_cb_t cb);


/**
 * @ingroup tcf0
 * @brief Initializes the TCF0 module and is the first routine called.
 * @pre None.
 * @param None.
 * @return None.
 */
void TCF0_Initialize(void);


/**
 * @ingroup tcf0
 * @brief Resets the TCF0 module to the Default state.
 * @pre None.
 * @param None.
 * @return None.
 */
void TCF0_Deinitialize(void);
 

/**
 * @ingroup tcf0
 * @brief Returns the status of the TCF0 module.
 * @pre None.
 * @param None.
 * @return enum @b TCF_status_t:
 *  - @c TCF_STATUS_IDLE = 0 @c      - The timer is not running
 *  - @c TCF_STATUS_RUNNING = 1 @c   - The timer is running
 */
TCF0_status_t TCF0_StatusGet(void);


/**
 * @ingroup tcf0
 * @brief Starts TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param None.
 * @return None.
 */
void TCF0_Start(void);  


/**
 * @ingroup tcf0
 * @brief Stops TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param None.
 * @return None.
 */
void TCF0_Stop(void);


/**
 * @ingroup tcf0
 * @brief Selects the prescaler for TCF0. 
 * @pre None.
 * @param TCF_PRESC_t:
 * - @c TCF_PRESC_DIV1_gc @c  -     direct clock source
 * - @c TCF_PRESC_DIV2_gc @c  -     clock speed divided by 2
 * - @c TCF_PRESC_DIV4_gc @c  -     clock speed divided by 4
 * - @c TCF_PRESC_DIV8_gc @c  -     clock speed divided by 8
 * - @c TCF_PRESC_DIV16_gc @c -     clock speed divided by 16
 * - @c TCF_PRESC_DIV32_gc @c -     clock speed divided by 32
 * - @c TCF_PRESC_DIV64_gc @c -     clock speed divided by 64
 * - @c TCF_PRESC_DIV128_gc @c -    clock speed divided by 128
 * @return None.
 */
void TCF0_PrescalerSet(TCF_PRESC_t config);


/**
 * @ingroup tcf0
 * @brief Enables or disables the Run-in-Standby mode for TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param boolean:
 * - True - Enables sleep
 * - False - Disables sleep
 * @return None.
 */
void TCF0_StandBySleep(bool state);


/**
 * @ingroup tcf0
 * @brief Sets the Waveform Generation mode for TCF0.
 * @pre None.
 * @param TCF_WGMODE_t:
 * - @c TCF_WGMODE_FRQ_gc @c        -   Frequency
 * - @c TCF_WGMODE_NCOPF_gc @c      -   NCO Pulse-Frequency
 * - @c TCF_WGMODE_NCOFDC_gc @c     -   NCO Fixed Duty Cycle
 * - @c TCF_WGMODE_PWM8_gc @c       -   8-bit PWM
 * @return None.
 */
void TCF0_ModeSet(TCF_WGMODE_t mode);


/**
 * @ingroup tcf0
 * @brief Sets the clock source for TCF0.
 * @pre None.
 * @param TCF_CLKSEL_t:
 * - @c TCF_CLKSEL_CLKPER_gc @c    -  Peripheral Clock
 * - @c TCF_CLKSEL_EVENT_gc @c     -  Event as clock source
 * - @c TCF_CLKSEL_OSCHF_gc @c     -  Internal High Frequency Oscillator
 * - @c TCF_CLKSEL_OSC32K_gc @c    -  Internal 32.768 kHz Oscillator
 * - @c TCF_CLKSEL_PLL_gc @c       -  PLL
 * - @c TCF_CLKSEL_OSCBOOT_gc @c   -  Boot Oscillator
 * @return None.
 */
void TCF0_ClockSet(TCF_CLKSEL_t config);


/**
 * @ingroup tcf0
 * @brief Controls the Event Output mode for TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param uint8_t where only bits 6-7 are used:
 * - Bit 6 represents event output 0
 * - Bit 7 represents event output 1
 * @return None.
 */
void TCF0_Event_OutputMode(uint8_t value); 


/**
 * @ingroup tcf0
 * @brief Controls the Waveform outputs for TCF0.
 * @pre None.
 * @param uint8_t where only bits 0-3 are used:
 * - Bit 0 enables channel 0
 * - Bit 1 enables channel 1
 * - Bit 2 reverses the polarity on channel 0
 * - Bit 3 reverses the polarity on channel 1
 * @return None.
 */
void TCF0_OutputsSet(uint8_t value);    

/**
 * @ingroup tcf0
 * @brief Issues the software commands of Update, Restart or Reset over the TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param enum TCF_CMD_t:
 * - @c TCF_CMD_NONE_gc @c    -   No command
 * - @c TCF_CMD_UPDATE_gc @c  -   Force update
 * - @c TCF_CMD_RESTART_gc @c -   Force restart
 * @return None.
 */
void TCF0_SoftwareCommand(TCF_CMD_t command);


/**
 * @ingroup tcf0
 * @brief Configures the input event for TCF0.
 * @pre TCF0_Initialize() is already called.
 * @param uint8_t where only bits 0-3 are used:
 * - Bit 0 enables the event input
 * - Bits 1 and 2 select the action event (00 for restart, 01 for blank)
 * - Bit 3 enables the filter
 * @return None.
 */
void TCF0_Event_InputConfig(uint8_t config);


/**
 * @ingroup tcf0
 * @brief Enables the TCF0 Overflow, CMP0 or CMP1 interrupts.
 * @pre TCF0_Initialize() is already called.
 * @param uint8_t where only bits 0-2 are used:
 * - Bit 0 enables the OVF interrupt
 * - Bit 1 enables the CMP0 interrupt
 * - Bit 2 enables the CMP1 interrupt
 * @return None.
 */
void TCF0_Interrupts_Enable(uint8_t mask);


/**
 * @ingroup tcf0
 * @brief Disables the TCF0 Overflow, CMP0 or CMP1 interrupts.
 * @pre TCF0_Initialize() is already called.
 * @param uint8_t where only bits 0-2 are used:
 * - Bit 0 disables the OVF interrupt
 * - Bit 1 disables the CMP0 interrupt
 * - Bit 2 disables the CMP1 interrupt
 * @return None.
 */
void TCF0_Interrupts_Disable(uint8_t mask);

 
/**
 * @ingroup tcf0
 * @brief Retrieves the interrupt flags.
 * @pre TCF0_Initialize() is already called.
 * @param None.
 * @return @b uint8_t @n From the returned 8-bit word, only bits TCF_OVF_bm, TCF_CMP0_bm and TCF_CMP1_bm are used.
 */
uint8_t TCF0_Interrupts_FlagsGet(void);


/**
 * @ingroup tcf0
 * @brief Clears the interrupt flags.
 * @pre TCF0_Initialize() is already called.
 * @param uint8_t where only bits 0-2 are used:
 * - Bit 0 clears the OVF flag
 * - Bit 1 clears the CMP0 flag
 * - Bit 2 clears the the CMP1 flag
 * @return None.
 */
void TCF0_Interrupts_FlagsClear(uint8_t mask);


/**
 * @ingroup tcf0
 * @brief Gets the CNT register value.
 * @pre TCF0_Initialize() is already called.
 * @param None.
 * @return @b uint32_t.
 */
uint32_t TCF0_CounterGet(void);


/**
 * @ingroup tcf0
 * @brief Sets the CNT register value.
 * @pre None.
 * @param uint32_t. Only 24-bit data is used.
 * @return None.
 */
void TCF0_CounterSet(uint32_t value);


/**
 * @ingroup tcf0
 * @brief Sets the CMP register value for TCF0.
 * @pre None.
 * @param uint32_t. Only 24-bit data is used.
 * @return None. 
 */
void TCF0_CompareSet(uint32_t value);


/**
 * @ingroup tcf0
 * @brief Sets the pulse length of the generated waveform for TCF0.
 * @pre None.
 * @param TCF_WGPULSE_WIDTH_t:
 * - @c TCF_WGPULSE_CLK1_gc @c   -  High pulse is 1 clock period
 * - @c TCF_WGPULSE_CLK2_gc @c   -  High pulse is 2 clock periods
 * - @c TCF_WGPULSE_CLK4_gc @c   -  High pulse is 4 clock periods
 * - @c TCF_WGPULSE_CLK8_gc @c   -  High pulse is 8 clock periods
 * - @c TCF_WGPULSE_CLK16_gc @c  -  High pulse is 16 clock periods
 * - @c TCF_WGPULSE_CLK32_gc @c  -  High pulse is 32 clock periods
 * - @c TCF_WGPULSE_CLK64_gc @c  -  High pulse is 64 clock periods
 * - @c TCF_WGPULSE_CLK128_gc @c -  High pulse is 128 clock periods
 * @return None.
 */
void TCF0_NCO_PulseLengthSet(TCF_WGPULSE_t config);


/**
 * @ingroup tcf0
 * @brief Sets the CMP0 register value for TCF0.
 * @pre None.
 * @param uint8_t.
 * @return None.
 */
void TCF0_PWM_DutyCycle0Set(uint8_t value);


/**
 * @ingroup tcf0
 * @brief Sets the CMP1 register value for TCF0.
 * @pre None.
 * @param uint8_t.
 * @return None.
 */
void TCF0_PWM_DutyCycle1Set(uint8_t value);


/**
 * @ingroup tcf0
 * @brief Sets the CNT1 register value for TCF0 in PWM mode.
 * @pre None.
 * @param uint8_t.
 * @return None.
 */
void TCF0_PWM_PeriodSet(uint8_t value);

#endif /* TCF0_H */