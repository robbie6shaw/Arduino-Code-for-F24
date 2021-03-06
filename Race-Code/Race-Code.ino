#include <Arduino.h>

//Set Up
  //Set up Analog Inputs
    const byte ButtonInPin=0;
    const byte VAPin=1;
    const byte IAPin=2;
    const byte tachometerPin=3;

  //Set up Outputs
    const byte Porter5Pin=3;
    const byte LEDPin=13;

  //Set Up Variables
    int ButtonIn=0;
    int CycleCount=0;     //Begins counter for amount of cycles the program has run
    int readingCount = 0;
    int voltageList[]={0.0};
    int currentList[]={0,0};
    int rpmList[]={0,0};
    int tachVoltage = 244;

  //Set Up Liquid Crystal Display
    // include the library code:
    #include <LiquidCrystal.h>
    // initialize the library with the numbers of the interface pins
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup() {
  // put your setup code here, to run once:

  pinMode(Porter5Pin,OUTPUT);
  pinMode(LEDPin,OUTPUT);

  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int tStart = millis();
  
  //First 15 Seconds
    Serial.print('t=');
    Serial.println(String(tStart));

    voltageList [readingCount] = voltageList + testVoltage();
    currentList [readingCount]= currentList + testCurrent();
    readingCount ++;

    int rpm = 0;

    while (millis() < tStart + 15000){
      
      if (analogRead(tachometerPin) < tachVoltage){
        rpm ++;
        }
    
    }
  
  //15s - 30s
    Serial.print('t=');
    Serial.println(String(tStart+15000));

    voltageList [readingCount] = voltageList + testVoltage();
    currentList [readingCount]= currentList + testCurrent();
    readingCount ++;

    while (millis() < tStart + 30000 ){

      if (analogRead(tachometerPin) < tachVoltage){
        rpm ++;
        }
    
    }

  //30s - 45s
    Serial.print('t=');
    Serial.println(String(tStart+30000));

    voltageList [readingCount] = voltageList + testVoltage();
    currentList [readingCount]= currentList + testCurrent();
    readingCount ++;

    while (millis() < tStart + 45000 ){

      if (analogRead(tachometerPin) < tachVoltage){
        rpm ++;
        }
    
    }

  //45s - 60s
    Serial.print('t=');
    Serial.println(String(tStart+45000));

    voltageList [readingCount] = voltageList + testVoltage();
    currentList [readingCount]= currentList + testCurrent();
    readingCount ++;

    while (millis() < tStart + 60000 ){

      if (analogRead(tachometerPin) < tachVoltage){
        rpm ++;
        }
    
    }

    rpmList [readingCount/4] = rpm;
}

int testVoltage(){

  int RawVoltage = analogRead(VAPin); //Creates Temporary Variable for prelimanary voltage reading and sets the new voltage reading

  //Maths goes here

  String VoltageReading = String(RawVoltage); // Set the voltage into a string that can be read by the LCD

  lcd.setCursor(0,0); //Top Line Message
  lcd.print(VoltageReading); //LCD Voltage Display

  Serial.print('V=');
  Serial.println(VoltageReading);

  return RawVoltage; //Returns Voltage Reading 
}

int testCurrent(){

  int RawCurrent=analogRead(IAPin);//Creates Temporary Variable for prelimanary current reading and sets new current reading

  //Maths goes here

  String CurrentReading = String(RawCurrent); // Set the current into a string that can be read by the LCD

  lcd.setCursor(0,1); //Bottom Line Message
  lcd.print(CurrentReading); //LCD Current Display

  Serial.print('I=');
  Serial.println(CurrentReading);

  return RawCurrent; //Returns Current Reading
}