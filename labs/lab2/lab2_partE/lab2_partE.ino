#include "pitches.h"
#include <LiquidCrystal.h>

// notes in the melody:
int melody[] = {
  NOTE_D3,NOTE_D3,NOTE_D3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4, \
  NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_C4,NOTE_A3,0};
 
int noteDurations[] = {
  10,10,10,2,2,10,10,10,2,4, \
  10,10,10,2,4,10,10,10,2,4};


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean playSong = false;
boolean startTimer = false;
boolean setTimer = true;
bool doneFlag = false;


const int buttonPin = 1; 
int buttonState = 0;
int oldState = 0;
int currentTime = 0;
int setTime = 100;
int count = 0;
boolean countdown = true;


void setup() {
  lcd.begin(16, 2);
  lcd.print("Star Wars");
  pinMode(buttonPin, INPUT);
  Serial.begin (9600);
  Serial.println("Start");
}


void loop() {
     if (doneFlag == false)
    {
        delay (2000);
        doneFlag = true;
    }
    
    if(countdown){
      lcd.setCursor(0, 1);
      currentTime = 5 - (millis() / 1000);
      lcd.print(currentTime); 
    }
    
  if(currentTime == 0){
      for (int thisNote = 0; thisNote < 20; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = (1000 / noteDurations[thisNote]);
      tone(8, melody[thisNote], noteDuration);
    
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      countdown = false;
    }
  }

}
