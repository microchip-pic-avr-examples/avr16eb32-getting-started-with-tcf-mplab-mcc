[![MCHP](./images/microchip.png)](https://www.microchip.com)

# Getting Started with Timer/Counter Type F (TCF)

This repository contains examples of MCC Melody generated source code for the new TCF of the AVR<sup>®</sup> EB' family of devices. This example provides two application examples, along with their functionalities.

 * [<strong>Generate Two Constant On-Time PWM Signals in NCO Pulse-Frequency Waveform Generation Mode using the TCF:</strong>](./NCO-Pulse-Length-Demo) In this use case, the TCF is configured to generate an overflow event on the compare registers at a fixed frequency while increasing the waveform duty cycle, through all possible lengths.
  * [<strong>Generate Two Variable-Frequency Signals in NCO-Fixed Mode using the TCF:</strong>](./NCO-Fixed-Duty-Cycle-Demo) In this use case, the TCF is configured to generate an overflow event on the compare registers on a range of frequencies (from 10 Hz to 100 KHz).
 

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

<br><img src="images/AVR16EB32_Cnano_Board.png">