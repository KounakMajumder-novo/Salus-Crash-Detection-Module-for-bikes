#include <SoftwareSerial.h>

#define RX_PIN 2   // SIM800 TX -> Arduino 2
#define TX_PIN 3   // SIM800 RX -> Arduino 3

SoftwareSerial sim800(RX_PIN, TX_PIN);

// Your number:
const char PHONE_NUMBER[] = "+919163081411";

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);

  delay(3000);               // wait for module to boot

  sim800.println("AT");      // test
  delay(500);

  // ----- MAKE CALL -----
  sim800.print("ATD");
  sim800.print(PHONE_NUMBER);
  sim800.println(";");
  Serial.println("Calling...");

  delay(15000);              // ring for 15 seconds

  // ----- HANG UP -----
  sim800.println("ATH");
  Serial.println("Hang up");
}

void loop() {
  // pass serial data for debugging
  if (sim800.available()) Serial.write(sim800.read());
  if (Serial.available()) sim800.write(Serial.read());
}
