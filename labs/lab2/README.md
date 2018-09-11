# Make a Digital Timer!
 
## Overview
For this assignment, you are going to 

A) [Solder your LCD panel](#part-a-solder-your-lcd-panel)

B) [Write text to an LCD Panel](#part-b-writing-to-the-lcd) 

c) [Using a time-based digital sensor!](#part-c-using-a-time-based-digital-sensor)

D) [Make your Arduino sing!](#part-d-make-your-arduino-sing)

E) [Make your own timer](#part-e-make-your-own-timer) 
 
## In The Report
Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

[here]https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab2/media/IMG_9419.jpeg

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**
1.5V

**b. What voltage level do you need to power the display backlight?**
3.3V

**c. What was one mistake you made when wiring up the display? How did you fix it?**
The display was not showing any text! Unfortunately, it was hard to figure out why this was because my wires were messy. My solution was to redesign my wiring by using another board for the LED, making it easier to see how everything was connected.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**
```
 lcd.print("hello, world!");
```
to
```
 lcd.print(“Christopher Caulfield”);
```

**e. Include a copy of your Lowly Multimeter code in your lab write-up.**
```
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int inputPin = A0;
int value = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Christopher");
}

void loop() {
  value = analogRead(inputPin);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
   lcd.print(value);
}
```

## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**
https://www.youtube.com/watch?v=bmtV6Z6IwUo&feature=youtu.be

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
Just add "/2"
```
 int noteDuration = (1000 / noteDurations[thisNote])/2;
```
 
**b. What song is playing?**
Star Wars
https://www.youtube.com/watch?v=c2OlojW7ZOo&feature=youtu.be

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**
First a delay before beginning, then does a countdown - to play the Star Wars song!

Code: https://github.com/ctcaulfield/Interactive-Lab-Hub/tree/master/labs/lab2/lab2_partE

