 int voltageR = 0;


  //Set Up Liquid Crystal Display
    // include the library code:
    #include <LiquidCrystal.h>
    // initialize the library with the numbers of the interface pins
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
    pinMode(13, OUTPUT);

   // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    
  //set up Serial
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    voltageR = analogRead(1);
    String voltageRStr = String(voltageR);
    lcd.setCursor(0,0);
    lcd.print(voltageRStr);
    Serial.println(voltageR);
    delay(1000);
}
