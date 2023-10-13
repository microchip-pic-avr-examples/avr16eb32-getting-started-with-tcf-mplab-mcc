/*
 * File:   main.c
 * Author: M69147
 *
 * Created on July 29, 2022, 12:16 PM
 */

#define F_CPU 20000000UL
#define TCF0_NCOFD_HZ_TO_INCREMENT(HZ, F_CLOCK, TCF0_PRESCALER)   (uint32_t)(((float)(HZ) * 33554432.0 * (TCF0_PRESCALER)) / ((float)(F_CLOCK)) + 0.5)

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
    TCF0.CTRLB |= TCF_WGMODE_NCOFDC_gc;
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

void TCF0_Initialize(void)
{
   TCF0_OutputsSet(TCF_WO0EN_bm | TCF_WO1EN_bm);
   TCF0_ClockSet(TCF_CLKSEL_CLKPER_gc);
   TCF0_PrescalerSet(TCF_PRESC_DIV1_gc); 
   TCF0_ModeSet(TCF_WGMODE_NCOFDC_gc); 
   TCF0_CounterSet(0);
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(10, 20000000, 1));
}

void NCO_Fixed_DutyCycle_Demo(void)
{   
   TCF0_Start();
   _delay_ms(600);
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(100, 20000000, 1));
   _delay_ms(60);
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(1000, 20000000, 1));
   _delay_ms(6);
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(10000, 20000000, 1));
   _delay_us(600);
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(100000, 20000000, 1));
   _delay_us(60);
   TCF0_Stop();
   TCF0_CompareSet(TCF0_NCOFD_HZ_TO_INCREMENT(10, 20000000, 1));
}


void main(void) 
{   
    CLOCK_Initialize();
    TCF0_Initialize();
    while(1)
    {
        NCO_Fixed_DutyCycle_Demo();
        _delay_ms(1000);
    }    
}
