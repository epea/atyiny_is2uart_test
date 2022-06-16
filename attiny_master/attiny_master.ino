#include <SoftwareSerial.h>
#include <TinyWireM.h>

#define LED_PIN 1

#define RX_PIN 3
#define TX_PIN 4

#define SLAVE_ADDR   0x08

SoftwareSerial softSerial =  SoftwareSerial(RX_PIN, TX_PIN);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  softSerial.begin(9600);
  softSerial.println("Master start");

  TinyWireM.begin();
  softSerial.println("Wire start");
}

bool flg = true;
int counter =0;
void loop() {
  digitalWrite(LED_PIN, flg);
  flg = !flg;
  softSerial.printf("Loop [%d]\n",counter++);

  softSerial.println("by available");
  int code = TinyWireM.requestFrom(SLAVE_ADDR, 1);
   if ( code == 0){
    softSerial.println(TinyWireM.read());
   } else {
    softSerial.printf("error with code[%d]\n",code);
   }
  delay(500);
}
