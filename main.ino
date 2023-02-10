// Library for LCD display
#include <LiquidCrystal_I2C.h>
// Libraries for temperature
#include <OneWire.h>
#include <DallasTemperature.h>
// Defines the temperatur sensor pin to get data
const int TMP_PIN = 2; 

OneWire oneWire(TMP_PIN);         
DallasTemperature tempSensor(&oneWire);

// Defines pin to check if the water level is sufficient
const int waterPin = 3;

// Temperature in Celsius
float tempC;    
// Defines default light level
int LDRvalue = 0;
// Contains text to describe water level
String waterLevel = "";

// Readies the LCD display at the 0x27 address
LiquidCrystal_I2C lcd(0x27, 16, 4);
//
#define LDRpin A3



void setup()
{ 
  pinMode(waterPin, INPUT_PULLUP);
  // Starts the sensor
  tempSensor.begin();    
  // Starts serial port used for debugging
  Serial.begin(9600);
  // Starts LCD display
  lcd.init();
  lcd.backlight();



}

void loop() 
{
  
 // If statement checks if there is a connection between the wires and returns the current state of the water 
  if(digitalRead(waterPin) == HIGH){
    waterLevel = "Low";
    }
    else{
      waterLevel = "Good";
    }
  
  
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
// Lines for displaying the enviroment's current condition
lcd.clear();
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

lcd.setCursor(5,1);
lcd.print(tempC); 
lcd.setCursor(7,2);
lcd.print(LDRvalue);
lcd.setCursor(13,3);
lcd.print(waterLevel);
// Delay between status checks
delay(10);

}