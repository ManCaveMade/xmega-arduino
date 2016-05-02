/*
  ESP-USB Serial Passthrough for Quark One

  Receives from the ESP-8266's serial port, sends to the USB serial port.
  Receives from USB serial port, sends to the ESP-8266's serial port.

  You can use this to debug / develop sketches for the Quark One's ESP-01 module.
  Of course, bootloader mode of the Quark One achieves the same thing.
  
  Created 1 May 2016 by Mitchell A. Cox (ManCave Made)

  This example code is in the public domain.
*/

void InitESP() {
  SerialESP.begin(115200); // The SerialESP keyword is defined for convenience in the library (could use Serial5 too).

  pinMode(26, OUTPUT); // GPIO2
  pinMode(27, OUTPUT); // GPIO0
  pinMode(30, OUTPUT); // RST
  pinMode(31, OUTPUT); // CH_PD
  
  // Reset the ESP-01 module into normal mode.
  digitalWrite(31, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH); // Set this LOW for flash mode
  digitalWrite(30, LOW);
  delay(1);
  digitalWrite(30, HIGH);
}

void setup() {
  // Init the USB CDC serial port
  Serial.begin(115200); 
  
  // Wait 5 seconds to give the user time to open Termite or some other serial console
  delay(5000); 
  Serial.println("Making it rain...");

  InitESP();
  // Expect a little bit of garbage text (ESP-8266 bootup text, etc.) and then you should see
  // some proper text on the console.
}

void loop() {
  // It's possible that some bytes may be lost so for a proper implementation
  // a ring buffer should be used.
  
  // Read from ESP, send to USB:
  if (SerialESP.available()) {
    int inByte = SerialESP.read();
    Serial.write(inByte);
  }

  // Read from USB, send to ESP:
  if (Serial.available()) {
    int inByte = Serial.read();
    SerialESP.write(inByte);
  }
}