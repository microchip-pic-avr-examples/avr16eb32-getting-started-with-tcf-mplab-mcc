[![MCHP](./images/microchip.png)](https://www.microchip.com)

# Getting Started with Timer/Counter Type F (TCF)

This repository contains examples of bare metal and MCC Melody generated source code for the new TCF of the AVREB family of devices as described in TBxxxx. There are two applications described in this document. Each application's configuration in MCC Melody is explained step by step and the functionality  is also explained.

 * [<strong>Generate Two Constant On-Time PWM Signals in NCO Pulse-Frequency Waveform Generation Mode using the TCF:</strong>](./NCO-Pulse/readme.md) In this use case, configure the TCF to  generate an overflow event on the CMP0 and CMP1 at a fixed frequency while increasing (through all possible lengths) the waveform duty-cycle. (for more details, see [<strong></strong>]()).
  * [<strong>Generate Two Variable-Frequency Signals in NCO-Fixed Mode using the TCF:</strong>](./NCO-Fixed/readme.md)  [<strong></strong>]() In this case, configure TCF to generate an overflow event on CMP0 and CMP1 on a range of frequencies (from 10 Hz to 100 KHz).
 (for more details, see [<strong></strong>]()).

## Related Documentation
More details and code examples on the AVR16EB32 can be found at the following links:
- [TBxxxx - Getting Started with Timer/Counter Type F (TCF)](insert url link here)
- [AVR16EB32 Product Page](insert url link here)
- [AVR16EB32 Code Examples on GitHub](insert url link here)

## Software Used
- [MPLAB X IDE v6.15 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [AVR-Ex DFP-2.5.184 or newer Device Pack](insert url link here)

## Hardware Used
- AVR16EB32 Cnano [(AVR16EB32)](insert url link here)

## Setup
The AVR16EB32 Cnano Development Board is used as test platform.

<br><img src="images/AVR16EB32_Cnano_Board.png">