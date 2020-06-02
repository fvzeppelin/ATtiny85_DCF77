# ATtiny85_DCF77
A Digispark is used to evaluate a DCF77 module. The sketch is based on the InternalClockSync example the library

https://github.com/thijse/Arduino-DCF77

It is modified to output the time to a software serial on pins P0 and P1.

As the compiled sketch uses more flash than available with the bootlader, it must be programmed with an ISP, omitting the bootloader. I have used the ATtiny board definitions from

https://github.com/damellis/attiny/

## Pin assignment

P0: RX

P1: TX

P2: Time signal from DCF77

P3: P(ower)ON of DCF77 (will be set to LOW on setup to start the DCF module)
