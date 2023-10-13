/*
 * File:   main.c
 * Author: M69147
 *
 * Created on July 29, 2022, 12:16 PM
 */

#define F_CPU 20000000UL
#define TCF0_NCOPL_HZ_TO_INCREMENT(HZ, F_CLOCK)   (uint32_t)(((float)(HZ) * 16777216.0) / (float)(F_CLOCK) + 0.5)

#include <util/delay.h>
#include <avr/io.h>


void CLOCK_Initialize(void)
{
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x0);
}

void TCF0_OutputsSet(uint8_t value)     
{      
    while((TCF0.STATUS & TCF_CTRLABUSY_bm) != 0){};
    TCF0.CTRLC = TCF_WO0EN_bm | TCF_WO1EN_bm;
}

void TCF0_ClockSet(TCF_CLKSEL_t config)
{
    TCF0.CTRLB |= TCF_CLKSEL_CLKPER_gc;    
}

void TCF0_PrescalerSet(TCF_PRESC_t config)
{     
    while((TCF0.STATUS & TCF_CTRLABUSY_bm) != 0){};
    TCF0.CTRLA  |= TCF_PRESC_DIV1_gc;
}
void TCF0_ModeSet(TCF_WGMODE_t mode)
{    
    TCF0.CTRLB |= TCF_WGMODE_NCOPF_gc;
}

void TCF0_CounterSet(uint32_t value)
{
    while((TCF0.STATUS & TCF_CNTBUSY_bm) != 0){};   
    TCF0.CNT0 = (uint8_t)value;  
}

void TCF0_CompareSet(uint32_t value)
{
    while((TCF0.STATUS & TCF_CMP0BUSY_bm) != 0){};
    TCF0.CMP = value; 
}

void TCF0_Start(void)
{
    while((TCF0.STATUS & TCF_CTRLABUSY_bm) != 0){};
    TCF0.CTRLA |=  TCF_ENABLE_bm;
}

void TCF0_Stop(void)
{
    while((TCF0.STATUS & TCF_CTRLABUSY_bm) != 0){};
    TCF0.CTRLA &= ~TCF_ENABLE_bm;   
}

void TCF0_NCO_PulseLengthSet(TCF_WGPULSE_t config)
{
    uint8_t temp; 
    while((TCF0.STATUS & TCF_CTRLCBUSY_bm) != 0){};       
    temp = (TCF0.CTRLC & ~TCF_WGPULSE_gm) |
               (  config   &  TCF_WGPULSE_gm); 
    TCF0.CTRLC = temp;
}

void TCF0_Initialize(void)
{
   TCF0_OutputsSet(TCF_WO0EN_bm | TCF_WO1EN_bm);
   TCF0_ClockSet(TCF_CLKSEL_CLKPER_gc);
   TCF0_ModeSet(TCF_WGMODE_NCOPF_gc);
   TCF0_CompareSet(TCF0_NCOPL_HZ_TO_INCREMENT(125000, 20000000)); 
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK1_gc);
   TCF0_CounterSet(0);
}

void NCO_Pulse_Length_Demo(void)
{
   TCF0_Start(); 
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK2_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK4_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK8_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK16_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK32_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK64_gc);
   _delay_us(20);
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK128_gc);
   _delay_us(18);
   TCF0_Stop();
   TCF0_NCO_PulseLengthSet(TCF_WGPULSE_CLK1_gc);
}


void main(void) 
{  
    CLOCK_Initialize();
    TCF0_Initialize();
    while(1)
    {
        NCO_Pulse_Length_Demo();
        _delay_ms(20);
    }    
}
