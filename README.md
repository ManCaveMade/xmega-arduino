# xmega-arudino

Original Author: flabbergast (https://github.com/flabbergast/xmega-arduino). Version 1.6.2

Modified by: Mitchell A. Cox (2 May 2016) (https://github.com/ManCaveMade/xmega-arduino) to add Quark One. Version 1.6.3

## Introduction

This add-on to [Arduino] {at least 1.6.2} adds support for ATMEL's XMEGA
line of microcontrollers.

Most of the hard work has been done by [Xmegaduino] folks. But I just
wanted an add-on to regular [Arduino] IDE.

I've added support for USB enabled atxmega chips (at the moment, two
xmega128A4U boards tested).

### Caveats (mainly for USB boards)

- USB support is alpha quality - so may be quite buggy.
- Only USB support present at the moment is for Serial (e.g. like the standard Arduino Leonardo). So no Keyboard, Mouse ... (like  [Teensyduino]) support yet.
- Autoreset is not implemented - you need to put your board into bootloader mode manually before uploading.
- Various third-party libraries might (and most probably do) need some adjustments to work with XMEGAs.

## Installation

Download zip (button on the right) and unpack to your `ARDUINO_SKETCHES_FOLDER/hardware`. This is probably in your "My Documents\Arduino" folder in Windows. Restart IDE.

## Usage

Select one of the Xmega boards in your IDE. Enjoy! Most standard Arduino examples should work. :)

The Quark One has some specific examples to use the onboard ESP-01 module, for example.

## Remarks and ramblings

- The USB stack is based on my quick-and-dirty XMEGA-USB code, based
  originally on Nonolith Labs' [USB-XMEGA] {so not on
  Dean Camera's excellent [LUFA] library - mainly because I didn't want
  to have to deconstruct [LUFA]'s complicated build system}. So quite
  possibly it's buggy. However it should be good enough for some basic
  Serial support.
-- Need to add support for USB serial number as done in LUFA to avoid zillions of Windows COM?? numbers.
- Tested on [X-A4U-stick], [MT-DB-X4] xmega128A4U breakout from [MattairTech] and [Quark One]
- `dfu-programmer` on linux might claim that 'No device present' even if
  the DFU bootloader shows up on `lsusb`. It's a permissions problem
  then - give your user enough permissions to access that usb device
  (google usb device permissions udev rule to see how can you fix that
  on your particular system).

### Hardware Notes

#### MT-DB-X4 from MattairTech

Digital pins go around the board from `0` = `A0`, to `29` = `E3`, with
the exception `30` = `D6` and `31` = `D7`. In particular, the LED is
digital `27` and the jumper is digital `26`.

Analog pins go from `A0` = `A0` to `A7` = `A7` and then `A8` = `B0`, up
to `A11` = `B3`.

#### X-A4U stick

The pins numbers are described on the [X-A4U-stick] webpage.

#### Quark One from ManCave Made

Pins are defined as written on the silkscreen on the [Quark One]. You can refer to them in your code as PinA0, PinB2, etc.



[Teensyduino]: https://www.pjrc.com/teensy/teensyduino.html
[LUFA]: http://www.fourwalledcubicle.com/LUFA.php
[Xmegaduino]: https://github.com/akafugu/Xmegaduino
[Arduino]: http://arduino.cc
[X-A4U-stick]: https://flabbergast.github.io/x-a4u-r2
[dfu-programmer]: https://dfu-programmer.github.io/
[USB-XMEGA]: https://dfu-programmer.github.io/
[MattairTech]: https://www.mattairtech.com/
[MT-DB-X4]: https://www.mattairtech.com/index.php/featured/mt-db-x4.html
[Quark One]: https://github.com/ManCaveMade
