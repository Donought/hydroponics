#include <LiquidCrystal_I2C.h>




#define BUTTON_PIN 4
#define LDRpin A3
int LDRValue = 0;



// Include the Arduino Stepper Library
#include <Stepper.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);

int counter = 0;
int mad = 210;

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);

     lcd.init();

  // First row
  lcd.backlight();
  lcd.setCursor(2,2);
  //Text som skal vises
  lcd.setCursor(0,0);
    lcd.print("Navn:");
    lcd.print("Capella");


  pinMode(BUTTON_PIN,INPUT_PULLUP);
  
}

void loop() 
{

  LDRValue = analogRead(LDRpin);
  Serial.println(LDRValue);
  delay(10);
  
  // step one revolution in one direction:
Serial.println(digitalRead(BUTTON_PIN));

byte buttonState = digitalRead(BUTTON_PIN);
buttonState = 0;
if(buttonState == 0){
  myStepper.step(stepsPerRevolution);
counter+=1;
mad-=10;
if(mad<0){
  mad+=10;
}
}
lcd.setCursor(0,0);
lcd.print("Placeholder1");
lcd.setCursor(0,1);
lcd.print("placeholder2");
lcd.setCursor(0,2);
lcd.print("placeholder3");
lcd.setCursor(0,3);
lcd.print("placeholder4");

}