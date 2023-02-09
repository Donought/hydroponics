
#include <LiquidCrystal_I2C.h>
// Libraries for temperature
#include <OneWire.h>
#include <DallasTemperature.h>
// Defines the temperatur sensor pin to get data
const int SENSOR_PIN = 2; 

OneWire oneWire(SENSOR_PIN);         
DallasTemperature tempSensor(&oneWire);

// Temperature in Celsius
float tempC;    
int LDRvalue = 0;

// Include the Arduino Stepper Library
#include <Stepper.h>
// Readies the LCD display at the 0x27 address
LiquidCrystal_I2C lcd(0x27, 16, 4);

#define LDRpin A3



void setup()
{ // Starts the sensor
  tempSensor.begin();    
  // Starts serial port used for debugging
  Serial.begin(9600);
  // Starts LCD display
  lcd.init();
  lcd.backlight();
lcd.setCursor(0,0); 
lcd.print("Current status:");
lcd.setCursor(0,1);
lcd.print("Tmp: ");
lcd.setCursor(6,1);
lcd.print("°C");
lcd.setCursor(0,2);
lcd.print("Light:");
lcd.setCursor(0,3);
lcd.print("Water level: ");



}

void loop() 
{
// Reads the current light level near the LDR and saves it to variable
  LDRvalue = analogRead(LDRpin);
  // LDR print for debugging
  Serial.println(LDRvalue);
  
//Requests the current temperature from the sensor
tempSensor.requestTemperatures();   
// Saves the current temperature to a variable          
  tempC = tempSensor.getTempCByIndex(0);  
// Prints for debugging
  Serial.print("Temperature: ");
  Serial.print(tempC);    
  Serial.println("°C");

lcd.setCursor(5,1);
lcd.print(tempC,1) // Comma might be redundant;
lcd.setCursor(7,2);
lcd.print(LDRvalue);
lcd.setCursor(0,3);
lcd.print("NOPE");
// If this fails use lcd.clear between updates
// Delay between status checks
delay(100);

}