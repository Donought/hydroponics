
#include <LiquidCrystal_I2C.h>

// Libraries for temperature
#include <OneWire.h>
#include <DallasTemperature.h>


#define BUTTON_PIN 4


// Libraries for temperature
#include <OneWire.h>
#include <DallasTemperature.h>

const int SENSOR_PIN = 4; // Temperatur data pin

OneWire oneWire(SENSOR_PIN);         
DallasTemperature tempSensor(&oneWire);

float tempCelsius;    // temperature in Celsius



// Include the Arduino Stepper Library
#include <Stepper.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);

int counter = 0;
int mad = 210;



void setup()
{
  tempSensor.begin();    // initialize the sensor
  // set the speed at 60 rpm:
  // initialize the serial port:
  Serial.begin(9600);

     lcd.init();


  lcd.backlight();


  pinMode(BUTTON_PIN,INPUT_PULLUP);
  
}

void loop() 
{
tempSensor.requestTemperatures();             // send the command to get temperatures
  tempCelsius = tempSensor.getTempCByIndex(0);  // read temperature in Celsius


  Serial.print("Temperature: ");
  Serial.print(tempCelsius);    // print the temperature in Celsius
  Serial.println("°C");

lcd.setCursor(0,0);
lcd.print("Placeholder1");
lcd.setCursor(0,1);
lcd.print("placeholder2");
lcd.setCursor(0,2);
lcd.print("placeholder3");
lcd.setCursor(0,3);
lcd.print("placeholder4");


  

}