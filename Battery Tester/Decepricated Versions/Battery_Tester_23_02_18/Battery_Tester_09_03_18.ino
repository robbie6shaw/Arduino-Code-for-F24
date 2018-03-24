#include <Arduino.h>
#include <LiquidCrystal.h>

/*Battery Testing Program
23 Feburary 2018

Expects:
LCD Monitor Attached,
VA form Attopilot Volatge Thingy to A1
IA from Attopilot Voltage Thingy to A2
 */

//Set up Analog Inputs
  const byte ButtonInP=0;
  const byte VAP=1;
  const byte IAP=2;

//Set up Outputs
  const byte RelayOnOff=3;
  const byte LEDP=13;

//Set Up Variables
  int ButtonIn=0;
  String VoltageL="";   //The voltage when the motor is not running
  String CurrentL="";   //Curent when the motor is not running
  String VoltageH1="";  //Voltage when the motor just starts running
  String CurrentH1="";  //Current when the motor just starts running
  String VoltageH2="";  //Voltage after a minute of motor run
  String CurrentH2="";  //Current after a minute of motor run
  int CycleCount=0;     //Begins counter for amount of cycles the program has run

//Set Up Liquid Crystal Display
  // include the library code:


  // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup() {
    // put your setup code here, to run once:

  //Digital Pin Setup
    pinMode(3, OUTPUT);
    pinMode(13, OUTPUT);

  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);


  }

void loop() {
    // put your main code here, to run repeatedly:
  while(CycleCount<90){
    
    testVoltage()= VoltageL;
    testCurrent()= CurrentL;
    
    digitalWrite(RelayOnOff,HIGH);

    delay(1000);  //Delays reading for 1s

    testVoltage()= VoltageH1;
    testCurrent()= CurrentH1;

    delay(60000);  //Delays reading for 60s

    testVoltage()= VoltageH2;
    testCurrent()= CurrentH2;

    digitalWrite(RelayOnOff,LOW); //Turn off Relay

    CycleCount ++;
    
    Serial.print("t=");
    Serial.println(CycleCount);

    Serial.print("a=");
    Serial.println(VoltageL);
    Serial.print("b=");
    Serial.println(CurrentL);
    Serial.print("c=");
    Serial.println(VoltageH1);
    Serial.print("d=");
    Serial.println(CurrentH1);
    Serial.print("e=");
    Serial.println(VoltageH2);
    Serial.print("f=");
    Serial.println(CurrentH2);
    Serial.println("#")
    
    delay(5000); // Delays reading for 5s
  };

  }
String testVoltage(){

  int RawVoltage=0;

  RawVoltage=analogRead(VAP); //Sets new voltage reading to RawVoltage Variable

  //Maths goes here

  String VoltageReading= String(RawVoltage); // Set the voltage into a string that can be read by the LCD

  lcd.setCursor(0,0); //Top Line Message
  lcd.print(VoltageReading); //LCD Voltage Display

  return VoltageReading;
}

String testCurrent(){

  int RawCurrent=0;

  RawCurrent=analogRead(IAP);//Sets new current reading to RawCurrent Variable

  //Maths goes here

  String CurrentReading = String(RawCurrent); // Set the current into a string that can be read by the LCD

  lcd.setCursor(0,1); //Bottom Line Message
  lcd.print(CurrentReading); //LCD Current Display

  return CurrentReading;
}


