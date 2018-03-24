#include <Arduino.h>

const byte tachometerPin = 1;
const int MAGNETREADING = 233;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
 int tachometerRead() {
    
    int rpm = 0;
    int cycleEnd = millis() + 60000;
    
    while (millis() < cycleEnd){
      
      int tachometerBit = analogRead(tachometerPin);
      
      if (tachometerBit < MAGNETREADING) {
          rpm ++;
      }
    }
  }
}
