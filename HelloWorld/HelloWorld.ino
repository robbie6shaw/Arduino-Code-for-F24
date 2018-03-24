/*LCD Try Program
23 Feburary 2018

Expects:
LCD Monitor Attached,
Serial Monitor
 */

//Set up Analog Inputs

//Set up Outputs
  const byte LEDP=13;

//Set Up Variables
  int ButtonIn=0;
  int RawVoltage=0;
  int RawCurrent=0;

//set up time variable
  int timePassed=0;

//Set Up Liquid Crystal Display
  // include the library code:
  #include <LiquidCrystal.h>

  // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);



void setup() {
    // put your setup code here, to run once:
  //set up time variable
    int timePassed=0;
  //Digital Pin Setup
    pinMode(LEDP, OUTPUT);

  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

  //set up Serial
    Serial.begin(9600);


  }

void loop() {
    // put your main code here, to run repeatedly:
  while( timePassed < 20 ){
    digitalWrite(13,HIGH);
    String TopLineReading= "Hello World";
    String BottomLineReading= "Code by Robbie Shaw"; // Sets strings for LED
  
    lcd.setCursor(0,0); //Top Line Message
    lcd.print(TopLineReading); //LCD Voltage Display
  
  
    Serial.println(TopLineReading);
    Serial.println(BottomLineReading);
  
    ++timePassed;

    lcd.setCursor(0,1); //Bottom Line Message
    lcd.print(timePassed); //LCD Current Display

    Serial.println(timePassed);
    
    delay(1000); // Delays reading for 1 minute
  } ;
    lcd.setCursor(0,0);
    lcd.print('Sequence');
    lcd.setCursor(0,1);
    lcd.print('Finished');

  digitalWrite(13,LOW);

  }
