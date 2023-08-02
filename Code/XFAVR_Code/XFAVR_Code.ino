

//Includes the Arduino Stepper Library
#include <Stepper.h>

//Includes Libraries for OLED Screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
# include <Keypad.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Constants for Loop Sequences, relevant for stepper motor and keypad
const float numVials = 16;
const float stepsPerRevolution_Vial = 2048;
const float stepsPerRevolution_Valve = 2048;
float stepsPerVial = (stepsPerRevolution_Vial / numVials);
float stepsPerValve = (stepsPerRevolution_Valve / 4);
int counter = 1;
unsigned long start_millis;
unsigned long current_millis;
boolean on = false;
unsigned long start_delay;
unsigned long screen_delay;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper vial_rotator = Stepper(stepsPerVial, 22, 24, 23, 25);
Stepper valve_rotator = Stepper(stepsPerValve, 50, 52, 51, 53);


String inputString;
long inputInt;


//Begin setting pins for Keypad
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {A7, A6, A5, A4};
byte colPins[COLS] = {A3, A2, A1, A0};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//---------------------------------------------------------------------------//


void setup() {
  vial_rotator.setSpeed(50);
  valve_rotator.setSpeed(20);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(1, 16);
  display.println("Welcome");


  display.display();
  delay(2000);
  screen_delay=0;
}


void loop()
{
  if (on == false){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(1, 16);
    display.println("Awaiting");
    display.println("Input");
    display.display();
    if (current_millis-screen_delay>1000){
      display.clearDisplay();
      display.setCursor(1, 16);
      display.println("Awaiting");
      display.println("Input...");
      display.display(); 
    }
    if(current_millis-screen_delay>2000){
      display.clearDisplay();
      screen_delay=current_millis;
    }
  
  }
  else{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    String vial_prefix = "Seconds/Vial : ";
    String runtime_prefix = "Vial Runtime (s): ";
    String counter_prefix = "Vial Number: ";
    String time_remaining= "Time Remain (m): ";
    display.print(vial_prefix);
    display.println(inputInt);
    display.println("");
    
    display.print(runtime_prefix);
    display.println(int((current_millis-start_millis)/1000)+1);
    display.println("");
    
    display.print(counter_prefix);
    display.println(counter);
    display.println("");
    
    display.print(time_remaining);
    display.println(float(inputInt*(numVials-counter)/60), 1);
    display.println("");

    display.display();
  }
  
  char key = customKeypad.getKey();
  if (key) {
    Serial.println(key);

    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        start_millis = millis();

      }
    } else if (key == '*') {
      inputString = "";                 // clear input
    }
  }

  current_millis = millis();
//  Serial.println(inputInt);


  if (key == 'A') {
    on = !on;
    Serial.println(on);
    // turn valve to open position
    for (int x = 0; x < stepsPerValve; x++)
    {
      valve_rotator.step(-1);
    }
    Serial.println("should open from initial closed position");
    delay(2000);

  }
  if (current_millis - start_millis >= inputInt * 1000) {
    if (counter <= 16 && on == true) {
//      Serial.println(counter);
      // turn valve to close position before rotation
      for (int x = 0; x < stepsPerValve; x++)
      {
        valve_rotator.step(-1);
      }
      Serial.println("should close before rotation");
      delay(2000);
      if (counter < 16 && on == true) {
        // turn vial rotator (except last rotation; we don't to contaminate vial 1!)
        for (int x = 0; x < stepsPerVial; x++)
        {
          vial_rotator.step(-1);
        }
        //turn valve to open position after rotation
        for (int x = 0; x < stepsPerValve; x++)
        {
          valve_rotator.step(-1);
        }
        Serial.println("should open after rotation");
        delay(2000);
      }
      counter++;
      start_millis = current_millis+6000;
//      inputInt=inputInt+6;
    }
  }
    Serial.println(current_millis-start_millis);
}
