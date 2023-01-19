#include <LiquidCrystal_I2C.h>




#define BUTTON_PIN 4




// Include the Arduino Stepper Library
#include <Stepper.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);

int counter = 0;
int mad = 210;



void setup()
{
  // set the speed at 60 rpm:
  // initialize the serial port:
  Serial.begin(9600);

     lcd.init();


  lcd.backlight();


  pinMode(BUTTON_PIN,INPUT_PULLUP);
  
}

void loop() 
{


lcd.setCursor(0,0);
lcd.print("Placeholder1");
lcd.setCursor(0,1);
lcd.print("placeholder2");
lcd.setCursor(0,2);
lcd.print("placeholder3");
lcd.setCursor(0,3);
lcd.print("placeholder4");


  

}
