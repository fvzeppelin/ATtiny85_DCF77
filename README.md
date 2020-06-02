# ATtiny85_DCF77
A Digispark is used to evaluate a DCF77 module. The sketch is based on the InternalClockSync example the library

https://github.com/thijse/Arduino-DCF77

As the compiled sketch uses more flash than available with the bootlader, it must be programmed with an ISP, omitting the bootloader. I have used the ATtiny board definitions from

https://github.com/damellis/attiny/

