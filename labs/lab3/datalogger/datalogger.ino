#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_VCNL4010.h"
Adafruit_VCNL4010 vcnl;
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led = 9;  
int highestTime = 5;
int startTime = 0;
int totalTime = 0;
int state = 4;
int blinks = 0;

void setup() {
  digitalWrite(led, HIGH);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("VCNL4010 test");
  if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
  lcd.begin(16, 2);
  lcd.print("Ball Spin Timer!");
}

void loop() {

 Serial.print("Ambient: "); Serial.println(vcnl.readAmbient());
 Serial.print("Proximity: "); Serial.println(vcnl.readProximity());

 switch (state) {
  case 0:    
    startGame();
    break;
  case 1:  
    inGame();
    break;
  case 2:    
    highScore();
    break;
  case 3:    
    gameOver();
    break;
  case 4:    
    newGame();
    break;
  }   
  totalTime = millis() / 1000;
}

void startGame(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready.");
  delay(800);
  lcd.clear();
  lcd.print("Set..");
  delay(800);
  lcd.clear();
  lcd.print("GO!");
  delay(800);
  lcd.clear();
  lcd.setCursor(0, 1);
  delay(1500);
  startTime = totalTime;
  state = 1;
}

void inGame(){
  if(vcnl.readAmbient() > 700){
    int resultTime = totalTime - startTime;
    if(resultTime > highestTime){
      highestTime = resultTime;
      state = 2;
    }
    else{state = 3;}
  }
}

void gameOver(){
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("GAME OVER :(");
  delay(500);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("HiScore:");
  lcd.setCursor(0, 1);
  lcd.print(highestTime);
  delay(4000);
  state = 4;
}

void highScore(){
  digitalWrite(led, LOW);
  delay(50);
  digitalWrite(led, HIGH);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("HIGH SCORE!!");
  delay(500);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("HiScore:");
  lcd.setCursor(0, 1);
  lcd.print(highestTime);
  digitalWrite(led, LOW);
  delay(4000);
  digitalWrite(led, HIGH);
  state = 4;
}

void newGame(){
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("NEW GAME");
  delay(1000);
  state = 0;
}
