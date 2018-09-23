/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int state = 0;
int feetVal = 0; 
boolean swim = false;


void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  switch (state){
    case 0:
      newDive();
      break;
      
    case 1:
      feetDeep();
      break;

    case 2:
      swimup();
      break;    
  }

}

void feetDeep(){
  if (Serial.available() > 0) {
    feetVal = Serial.parseInt(); //read int or parseFloat for ..float...
    Serial.println("Okay, Chad is going to dive ");
    Serial.print(feetVal);
    Serial.print(" feet in the water");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    delay(3000);
    state = 2;
  }
}

void newDive(){
  Serial.println("Chad is an expert diver, please enter how many feet you would like him to dive...");
  Serial.print("I would like Chad, this many feet in the water and swim out:"); 
  state = 1;
}

void swimup(){
  if(feetVal > 0 && swim == false){
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 10; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    feetVal = feetVal - 10; 
    Serial.println("");
    Serial.println("Chad is ");
    Serial.print(feetVal);
    Serial.print(" feet in the water");
    Serial.println("");
  }
  else{
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Serial.println("Yay! Chad made it to the top! Thanks for helping Chad!");
    state = 0;
    delay(5000);
    swim = false;
  }
}
