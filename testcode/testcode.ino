#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
long duration;
int distance;
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
char code[4] = {'n','n','n','n'};
int buzzer = 12;
const int trigPin = 10;
const int echoPin = 11;
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup() {
    lcd.begin(16, 2);
    lcd.print("   Input Code");
    char f = 'd';
    lcd.setRGB(colorR, colorG, colorB);
    lcd.setCursor(6, 1);
    pinMode(buzzer,OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    
}
char getKeyPress(){
  while(true){
  char customKey = customKeypad.getKey();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    if((distance > 25)){
      return '*';
    }
    if(customKey){
      return customKey;
      }
    }
}
void loop() {
    char f = getKeyPress();
    lcd.print(f);
    code[1] = f;
    f = getKeyPress();
    lcd.print(f);
    code[2] = f;
    f = getKeyPress();
    lcd.print(f);
    code[3] = f;
    f = getKeyPress();
    lcd.print(f);
    code[4] = f;
    if((code[1] == '2') & (code[2] == '2') & (code[3] == '3') & (code[4] == '8')){
      lcd.setRGB(0, 255, 0);
      digitalWrite(buzzer,LOW);
      while(1){
      }
      }
    else{
      lcd.setRGB(255, 0, 0);
      digitalWrite(buzzer,HIGH);
      delay(1000);
      lcd.setCursor(6, 1);
      lcd.print("    ");
      lcd.setCursor(6, 1);
      lcd.setRGB(colorR, colorG, colorB);
      
    }
}
