/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define USE_RTC // Use RTC for millis etc.

#define REPEAT8(x) x, x, x, x, x, x, x, x
#define BV0TO7 _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7)
#define BV7TO0 _BV(7), _BV(6), _BV(5), _BV(4), _BV(3), _BV(2), _BV(1), _BV(0)

#define NUM_DIGITAL_PINS            30
#define NUM_ANALOG_INPUTS           12
#define EXTERNAL_NUM_INTERRUPTS     18

#define analogInputToDigitalPin(p)  ((p < 12) ? p : -1)
#define digitalPinHasPWM(p)         (((p) >= 12 && (p) <= 17) || ((p) >= 20 && (p) <= 27)))

//defines for PWM
// 980hz = 32Mhz / (2 x div x 0xFF)
#define PWM_490HZ TC_CLKSEL_DIV128_gc
#define PWM_980HZ  TC_CLKSEL_DIV64_gc
#define PWM_7843HZ TC_CLKSEL_DIV8_gc
#define PWM_15686HZ TC_CLKSEL_DIV4_gc
#define PWM_31373HZ TC_CLKSEL_DIV2_gc
  //to use the above, #define in the code: PWM_FREQ as one of the above.

static const uint8_t SS    = 16;
static const uint8_t MOSI  = 17;
static const uint8_t MISO  = 18;
static const uint8_t SCK   = 19;

static const uint8_t SDA = 12;
static const uint8_t SCL = 13;
static const uint8_t LED_BUILTIN = 9;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;

//R0 and R1 are special and can't be defined in the array below
static const uint8_t R0 = 30;
static const uint8_t R1 = 31;

#define Wire xmWireC

#define SPI_PORT	SPIC

// TODO this - what the heck does this do on XMEGA?
//#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 22) ? (&PCICR) : ((uint8_t *)0))
//#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
//#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
//#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
		// PORTLIST
		/*PC,
		PC,
		PC,
		PC,
		PC,
		PC,
		PC,
		PC,
		PB,
		PB,
		PA,
		PA,
		PA,
		PA,
		PA,
		PA,
		PA,
		PA,
		PE,
		PE,
		PE,
		PE,
		PB,*/
		REPEAT8(PA), // A0 - A7, 0 - 7
		PB, //B0, 8
		PB, //B1
		PB, //B2
		PB, //B3
		REPEAT8(PC), // C0 - C7, 12 - 19
		PD, //D0, 20
		PD, //D1
		PD, //D2
		PD, //D3
		PD, //D4
		PD, //D5
		PE, //E0, 26
		PE, //E1
		PE, //E2
		PE //E3, 29
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
		// PIN IN PORT
		// -------------------------------------------
		_BV( 0 ), // 0 (A) (Button)
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 4 ),
		_BV( 5 ),
		_BV( 6 ),
		_BV( 7 ),
		_BV( 0 ), // 8 (B)
		_BV( 1 ), // (LED)
		_BV( 2 ),
		_BV( 3 ),
		_BV( 0 ), // 12 (C)
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 4 ),
		_BV( 5 ),
		_BV( 6 ),
		_BV( 7 ),
		_BV( 0 ), // 20 (D)
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 4 ),
		_BV( 5 ),
		_BV( 0 ), // 26 (E) (ESP GPIO2)
		_BV( 1 ), // (ESP GPIO0)
		_BV( 2 ), // (ESP TXD (Arduino RX))
		_BV( 3 ) //29 (ESP RXD (Arduino TX))
		// 30 R0 (ESP RST)
		// 31 R1 (ESP CH_PD)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS
	// -------------------------------------------
	REPEAT8(NOT_ON_TIMER), //A not on timer
	NOT_ON_TIMER, //B not on timer
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER_C0A, //C (12)
	TIMER_C0B,
	TIMER_C0C,
	TIMER_C0D,
	TIMER_C1A,
	TIMER_C1B, // 17
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER_D0A, //D (20)
	TIMER_D0B,
	TIMER_D0C,
	TIMER_D0D,
	TIMER_D1A,
	TIMER_D1B,
	TIMER_E0A, //D (26)
	TIMER_E0B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER
};

const TC0_t* const PROGMEM timer_to_tc0_PGM[] = {
	NULL,

	&TCC0,
	&TCC0,
	&TCC0,
	&TCC0,
	NULL,
	NULL,

	&TCD0,
	&TCD0,
	&TCD0,
	&TCD0,
	NULL,
	NULL,

	&TCE0,
	&TCE0,
	&TCE0,
	&TCE0,
	NULL,
	NULL,
	};

const TC1_t* const PROGMEM timer_to_tc1_PGM[] = {
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	&TCC1,
	&TCC1,

	NULL,
	NULL,
	NULL,
	NULL,
	&TCD1,
	&TCD1,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

const TC2_t* const PROGMEM timer_to_tc2_PGM[] = {
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

const uint8_t PROGMEM timer_to_channel_PGM[] = {
	NOT_ON_TIMER,

    0,
    1,
    2,
    3,
    0,
    1,

    0,
    1,
    2,
    3,
    0,
    1,

    0,
    1,
    NOT_ON_TIMER,//2,
    NOT_ON_TIMER,//3,
    NOT_ON_TIMER,//0,
    NOT_ON_TIMER,//1,
};

const uint8_t PROGMEM adc_to_channel_PGM[] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9, //connected to LED so readings are hard
    10,
    11
};

#endif

/**************************************************************************
 *
 *  USB Configurable Options
 *
 **************************************************************************/

// You can change these to give your code its own name.  On Windows,
// these are only used before an INF file (driver install) is loaded.
#define STR_MANUFACTURER L"ManCave Made"
#define STR_PRODUCT      L"Quark One Serial"

// All USB serial devices are supposed to have a serial number
// (according to Microsoft).  On windows, a new COM port is created
// for every unique serial/vendor/product number combination.  If
// you program 2 identical boards with 2 different serial numbers
// and they are assigned COM7 and COM8, each will always get the
// same COM port number because Windows remembers serial numbers.
//
// On Mac OS-X, a device file is created automatically which
// incorperates the serial number, eg, /dev/cu-usbmodem12341
//
// Linux by default ignores the serial number, and creates device
// files named /dev/ttyACM0, /dev/ttyACM1... in the order connected.
// Udev rules (in /etc/udev/rules.d) can define persistent device
// names linked to this serial number, as well as permissions, owner
// and group settings.
#define STR_SERIAL_NUMBER  L"DEADB" //TODO: Look at getting this from the chip

// Mac OS-X and Linux automatically load the correct drivers.  On
// Windows, even though the driver is supplied by Microsoft, an
// INF file is needed to load the driver.  These numbers need to
// match the INF file.
#define VENDOR_ID               0x1d50
#define PRODUCT_ID              0x60eb

// When you write data, it goes into a USB endpoint buffer, which
// is transmitted to the PC when it becomes full, or after a timeout
// with no more writes.  Even if you write in exactly packet-size
// increments, this timeout is used to send a "zero length packet"
// that tells the PC no more data is expected and it should pass
// any buffered data to the application that may be waiting.  If
// you want data sent immediately, call usb_serial_flush_output().
#define TRANSMIT_FLUSH_TIMEOUT  40   /* in 1/8 milliseconds */


#endif
