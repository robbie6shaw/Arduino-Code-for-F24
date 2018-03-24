#include <Arduino.h>
/*Battery Testing Program
  10 March 2018

  Beta

  Expects:
  LCD Monitor Attached,
  Attopilot DC Voltage and Current connected to A1 and A2
*/
//Set Up
  //Set up Analog Inputs
    const byte ButtonInPin=0;
    const byte VAPin=1;
    const byte IAPin=2;

  //Set up Outputs
    const byte RelayPin=3;
    const byte LEDPin=13;

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
    #include <LiquidCrystal.h>
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
  
  //Loop for 90 minutes
  while(CycleCount<90){
    
    testVoltage()= VoltageL; //Unloaded Volatage Test
    testCurrent()= CurrentL; //Unloaded Current Test
    
    digitalWrite(RelayPin,HIGH); //Switches Relay, and therefore motor on

    delay(1000);  //Delays reading for 1s

    testVoltage()= VoltageH1; //Inital Loaded Voltage Test
    testCurrent()= CurrentH1; //Inital Loaded Curent Test

    delay(60000);  //Delays reading for 60s

    testVoltage()= VoltageH2; //Final Loaded Voltage Test
    testCurrent()= CurrentH2; //Final Loaded Current Test

    digitalWrite(RelayPin,LOW); //Turn off Relay

   //Add 1 to CycleCount
    CycleCount ++;
    
    //Write CycleCount to Serial
    Serial.print("t=");
    Serial.println(CycleCount);

    //Write Results to Serial
    Serial.print("a="); 
    Serial.print(VoltageL);
    Serial.print("b=");
    Serial.println(CurrentL);
    Serial.print("c=");
    Serial.println(VoltageH1);
    Serial.print('d=');
    Serial.println(CurrentH1);
    Serial.print('e=');
    Serial.println(VoltageH2);
    Serial.print('f=');
    Serial.println(CurrentH2);
    
    Serial.print('#')
    
    
    delay(5000); // Delays reading for 5s
  };
  }

String testVoltage(){

  int RawVoltage = analogRead(VAPin); //Creates Temporary Variable for prelimanary voltage reading and sets the new voltage reading

  //Maths goes here

  String VoltageReading = String(RawVoltage); // Set the voltage into a string that can be read by the LCD

  lcd.setCursor(0,0); //Top Line Message
  lcd.print(VoltageReading); //LCD Voltage Display

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
