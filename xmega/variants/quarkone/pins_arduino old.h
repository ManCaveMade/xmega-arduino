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

  Modified by Mitchell A. Cox for the Quark One

*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define USE_RTC // Use RTC for millis etc.

#define XMEGAA4U 

#define REPEAT8(x) x, x, x, x, x, x, x, x

#define NUM_DIGITAL_PINS            30
#define NUM_ANALOG_INPUTS           12
#define EXTERNAL_NUM_INTERRUPTS     36 

#define analogInputToDigitalPin(p)  ((p < 12) ? p : -1)
#define digitalPinHasPWM(p)         (((p) >= 2 && (p) <= 6) || ((p) >= 9 && (p)<= 11) || ((p) >= 14 && (p)<= 19))

static const uint8_t SS    = 16;
static const uint8_t MOSI  = 17;
static const uint8_t MISO  = 18;
static const uint8_t SCK   = 19;

static const uint8_t SDA = 12;
static const uint8_t SCL = 13;

static const uint8_t LED_BUILTIN = 9; //B1

//R0 and R1 are special and can't be defined in the array below
static const uint8_t R0 = 30;
static const uint8_t R1 = 31;

//Convenience labels that correspond to Quark One PCB labels
//MC: Why can't these be #defines?
static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;

/*
static const uint8_t B0 = 8;
static const uint8_t B1 = 9;
static const uint8_t B2 = 10;
static const uint8_t B3 = 11;

static const uint8_t C0 = 12;
static const uint8_t C1 = 13;
static const uint8_t C2 = 14;
static const uint8_t C3 = 15;
static const uint8_t C4 = 16;
static const uint8_t C5 = 17;
static const uint8_t C6 = 18;
static const uint8_t C7 = 19;

static const uint8_t D0 = 20;
static const uint8_t D1 = 21;
static const uint8_t D2 = 22;
static const uint8_t D3 = 23;
static const uint8_t D4 = 24;
static const uint8_t D5 = 25;

static const uint8_t E0 = 26;
static const uint8_t E1 = 27;
static const uint8_t E2 = 28;
static const uint8_t E3 = 29;
*/

#define Wire xmWireC
//#define Wire1 xmWireE

#define SPI_PORT	SPIC

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

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
		//_BV( 0 ),// 30 R0 (ESP RST)
		//_BV( 1 ),// 31 R1 (ESP CH_PD)
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
	NULL, //&TCE0,
	NULL, //&TCE0,
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

	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,

	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,
	&TCC2,

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

#endif
