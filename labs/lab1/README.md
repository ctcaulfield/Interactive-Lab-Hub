# IDD-Fa18-Lab1: Blink!

**A lab report by Christopher Caulfield*

## Part A. Set Up a Breadboard
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab1/media/board.png" height="50%" width="50%" >

## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**
Forgive me, I am very color blind, but I believe the colors are: Red, Red, Black, Black, Brown
 
**b. What do you have to do to light your LED?**
To light my LED I needed to create a circuit similar to shown in: https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/blob/docs/button_led_resistor_diagram.png. Connecting a button is the trigger point for the LED to light up.

## Part C. Blink a LED using Arduino


### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**
To make the LED blink the following code was changed:
```
pinMode(9, OUTPUT);
```

**b. What line(s) of code do you need to change to change the rate of blinking?**
Rate of blinking is changed by inputing a number in the delay() function. You could also randomize this using the random() function  
```
void loop() {
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(750);                       // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(750);                       // wait for a second
}
```


**c. What circuit element would you want to add to protect the board and external LED?**
The resistor can be added as a circuit element to reduce the current flow, protecting the board and LED.
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab1/media/board.png" height="50%" width="50%">


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**
Yes, turning the "wiper" determines how much resistence is being genereated to the circuit.
<img src="https://i0.wp.com/rntlab.com/wp-content/uploads/2016/02/Fig.-4.png?zoom=2&resize=460%2C181&ssl=1" height="50%" width="50%" >

Source: https://randomnerdtutorials.com/electronics-basics-how-a-potentiometer-works/

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

**b. What is analogWrite()? How is that different than digitalWrite()?**


## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

**d. Is information stored in your device? Where? How?**

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**

### 3. Build your light!

**Make a video showing off your Frankenlight.**

**Include any schematics or photos in your lab write-up.**
