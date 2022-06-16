#include <Wire.h>

byte b=0;

void setup() {
    Serial.begin(9600);
  Serial.println("slave START");
  Wire.begin(0x08);// Slave ID #8
  Wire.onRequest(requestEvent);
}

void loop() {
}

void requestEvent() {
  Serial.print("event call current data[");
   Serial.print(b);
   Serial.println("]");
  Wire.write(b++);
}
