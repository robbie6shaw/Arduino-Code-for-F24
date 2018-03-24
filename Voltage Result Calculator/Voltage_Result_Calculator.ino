#include <Arduino.h>
/* Voltage Calculation Program 
    03/03/18

    Requires:
    LCD Panel,
    Attopilot DC Voltage and Current Sense Connected to A1 and A2
    */

 //Set Up
    //Analog Inputs
        const byte ButtonInPin = 0;
        const byte VAPin = 1;
        const byte IAPin = 2;

    //Outputs
        const byte LEDPin = 13;   

    //Set up Variables

void setup (){

}

void loop (){

}

String testVoltage(){

  int RawVoltage = analogRead(VAPin); //Creates Temporary Variable for prelimanary voltage reading and sets the new voltage reading

  //Maths goes here

  String VoltageReading = String(RawVoltage); // Set the voltage into a string that can be read by the LCD

  lcd.setCursor(0,0); //Top Line Message
  lcd.print(VoltageReading); //LCD Voltage Display

  return VoltageReading; //Returns Voltage Reading 
}

int testVoltageInt(){

  int RawVoltage = analogRead(VAPin); //Creates Temporary Variable for prelimanary voltage reading and sets the new voltage reading

  //Maths goes here

  int VoltageReading = String(RawVoltage); // Set the voltage into a string that can be read by the LCD

  return VoltageReading; //Returns Voltage Reading 
}

String testCurrent(){

  int RawCurrent=analogRead(IAPin);//Creates Temporary Variable for prelimanary current reading and sets new current reading

  //Maths goes here

  String CurrentReading = String(RawCurrent); // Set the current into a string that can be read by the LCD

  lcd.setCursor(0,1); //Bottom Line Message
  lcd.print(CurrentReading); //LCD Current Display

  return CurrentReading; //Returns Current Reading
}

int testCurrentInt(){

  int RawCurrent=analogRead(IAPin);//Creates Temporary Variable for prelimanary current reading and sets new current reading

  //Maths goes here

  int CurrentReading = String(RawCurrent); // Set the current into a string that can be read by the LCD

  return CurrentReading; //Returns Current Reading
}