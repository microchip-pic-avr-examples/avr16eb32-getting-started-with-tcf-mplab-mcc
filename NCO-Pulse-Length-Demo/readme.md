[![MCHP](../images/microchip.png)](https://www.microchip.com)

## Generate Two Constant On-Time PWM Signals in NCO-Pulse Length Mode Using the TCF

The example shows how to set the TCF to generate two Constant-On-Time PWM signals.

## Related Documentation
More details and code examples on the AVR16EB32 can be found at the following links:
- [AVR<sup>®</sup> EB Product Page](https://www.microchip.com/en-us/product/AVR16EB32)
- [AVR<sup>®</sup> EB Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=AVR16EB32)

## Software Used
- [MPLAB® X IDE v6.15 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [AVR-Ex DFP-2.7.184 or newer Device Pack](https://packs.download.microchip.com/)
- [MPLAB® XC8 compiler v2.45](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8)
- [MPLAB® Code Configurator (MCC) v 5.3.7](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)
- [MPLAB® Code Configurator (MCC) Melody Core v 2.6.2 or newer](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)

## Hardware Used
- [AVR<sup>®</sup> EB Curiosity Nano](https://www.microchip.com/en-us/product/AVR16EB32)

## Setup
The AVR16EB32 Curiosity Nano Development Board is used as test platform.
<br><img src="../images/AVR16EB32_Cnano_Board.png">

## Functionality
After  the peripheral clock and the TCF are initialized, the ```NCO_Pulse_Length_Demo``` function is called in an infinite loop. 

The purpose of this function is to change the pulse length of the waveform which the timer outputs on the pin. The timer is started with a pulse length of 2 clock cycles and then run up to the maximum of 128 clock cycles. 

1 clock cycle takes 50 ns beacuse the timer is running at 20 MHz. 1 divided by 20 MHz equals 50 ns.

At the end the timer is stopped and the pulse length is reset to 1 clock cycle.

```
void NCO_Pulse_Length_Demo(void)
{
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

```
<br><img src="../images/ncoPlFlowchart.png">



<br>To generate this project using MPLAB® X IDE and the MPLAB® Code Configurator (MCC Melody, MCC Clasic is not supported on this device), follow the next steps:

<br>1. Open MPLAB X IDE and create a new project for AVR16EB32 device.


<br>2. Open MCC from the toolbar (more information on how to install the MCC plug-in can be found [here](https://onlinedocs.microchip.com/pr/GUID-1F7007B8-9A46-4D03-AEED-650357BA760D-en-US-6/index.html?GUID-D98198EA-93B9-45D2-9D96-C97DBCA55267).


<br>3.  In MCC Content Manager Wizard select MCC Melody then select the Finish button.<br><img src="../images/addMCC.png">
<br><img src="../images/selectMCCMelody.png">
<br><img src="../images/mccFinish.png">

<br>4.  Go to Project Resources, click System then click CLKCTRL and disable the Prescaler Enable button.
<br><img src="../images/selectCLKCTRL.png">
<br><img src="../images/disablePrescaler.png">

<br>5. From the Device Resources go to Drivers and click the Timer window, add the TCF module, then do the following configuration:
    <br> – Clock Divider: System clock (by default the divider should be 1 - System clock)
    <br> – Waveform Generation Mode: NCO Pulse-Length mode
    <br> – Waveform Generation Pulse Length: 1 Clock Period
    <br> – Requested Period[s]: 0.000008
    <br> – Waveform Output n : check the boxes from the Enable column for Waveform Output 0 and Waveform Output 1

<br><img src="../images/selectTCF.png">
<br>
<br>
<br><img src="../images/tcfPLSettings.png">


<br>6. In the Pin Grid View the PA0 and PA1 pins must be enabled by default. If not just toggle the buttons, it turns green if enabled.

<br><img src="../images/selectPins.png">


<br>7. In the Project Resources window, click the Generate button so that MCC will generate all the specified drivers and configurations.
<br>
<br>
<br><img src="../images/generateCode.png">
<br>


<br>8. After the MCC Melody generates the project files with the configuration explained above, edit the main.c file as explained here [(insert TB url link here)](insert TB url link here) at page 33.


## Operation
 1. Connect the board to the PC.

 2. Open the **TCF_NCO_Fixed_Duty_Cycle_MCC.X* or **TCF_NCO_Fixed_Duty_Cycle.X** solution in MPLAB X IDE.

 3. Right click on the project and select **Set as main project**.

<br><img src="../images/setAsMain.png">

 4. Build the **TCF_NCO_Fixed_Duty_Cycle_MCC.X** or **TCF_NCO_Fixed_Duty_Cycle.X**  project: click on **Clean and Build Project**.

<br><img src="../images/cleanAndBuild.png">

 5. Program the project to the board: click on **Make and Program Device**.

<br><img src="../images/flashProject.png">


## Results

The logic analyzer capture show how the TCF generates a waveform signal NCO Pulse-Length mode.

<br>Result: TCF is used to generate two pulse-width-modulated output signals with a frequency of 125 kHz and with a variable duration ranging from 1 clock cycle up to 128 clock cycles.

<br><img src="../images/ncoPlResult.png">


## Summary

This example depicted how to create a project in MCC using the TCF peripheral of ARVR16EB32. The TCF was configured to generate two PWM output signals on the default TCF output pins. The pulse length varies between 1 clock cycle and 128 clock cycles. The measured output confirms the expected result.