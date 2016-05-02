/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin.

 This example code is in the public domain.
 */

//This #define is not necessary, but allows you to use a higher PWM frequency.
//The default frequency is about 1 kHz but this is not normally sufficient.
//Available options on Quark One are: PWM_31373HZ, PWM_15686HZ, PWM_7843HZ, PWM_980HZ (default), PWM_490HZ
#define PWM_FREQ PWM_31373HZ

int led = PinC0;       // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
