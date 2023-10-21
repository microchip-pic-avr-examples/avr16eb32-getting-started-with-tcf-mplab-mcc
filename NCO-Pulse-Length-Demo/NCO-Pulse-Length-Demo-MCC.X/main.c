 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

void NCO_Pulse_Length_Demo(void)
{
    /* Configure the TCF to start counting from 0 */
    TCF0_CounterSet(0);
    
    /* Enable the TCF */
    TCF0_Start(); 
    
    /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 2 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK2_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 4 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK4_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 8 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK8_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 6 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK16_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 32 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK32_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 64 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK64_gc);
   
   /* Delay for 20 us */
   _delay_us(20);
   
   /* Configure the pulse-length to 128 clock cycles */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK128_gc);
   
   /* Delay for 25 us */
   _delay_us(25);
   
   /* Stop the timer */
   TCF0_Stop();
   
   /* Configure the pulse-length to 1 clock cycle */
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK1_gc);
}


int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        NCO_Pulse_Length_Demo(); 
        _delay_ms(20);
    }    
}