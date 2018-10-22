#include <FirmataParser.h>
#include <FirmataMarshaller.h>
#include <FirmataDefines.h>
#include <Boards.h>
#include <FirmataConstants.h>
#include <Firmata.h>
#include <math.h>
#include <Wire.h>
#include <rgb_lcd.h>

const int buttonPin = 2;          // the number of the pushbutton pin
const int ledPin =  13;           // the number of the LED pin
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

rgb_lcd lcd;

int colorR = 255;
int colorG = 0;
int colorB = 0;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void change_rgb(float temp) {
  float min_temp = 20.0;
  float max_temp = 25.5;
  if (temp <= min_temp) {
    colorR = 0;
    colorG = 0;
    colorB = 255;
  } else if (temp >= max_temp) {
    colorR = 255;
    colorG = 0;
    colorB = 0;
  } else {
    float k = (temp - min_temp)/(max_temp - min_temp);
    colorB = 255*k;
    colorR = 255*(1-k);
    colorG = 0;
  }
}

void setup() {
    Serial.begin(9600);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    pinMode(ledPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
}

void loop(){    

}
