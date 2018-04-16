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
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup() {
    lcd.begin(16, 2);
    lcd.print("On");
    char f = 'd';
}

void loop() {
     
    char f = getKeyPress();
    lcd.print(f);
}

char getKeyPress(){
  while(true){
  char customKey = customKeypad.getKey();
  if(customKey){
    return customKey;
    }
  }
}
