# Data Logger (and using cool sensors!)

*A lab report by Christopher Caulfield*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 Range: 0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**
10 bits
Source: https://learn.sparkfun.com/tutorials/analog-to-digital-conversion

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**
The value being printed from the sensor ranges from 0 to 1023, depending how much force is applied to the sensor.
Since, I used a 10K resistor the voltage was 4.9V. 
Source: https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**
The relationship is non-linear because it depends on the force applied. Here is an example on a log/log graph.
<img src="https://cdn-learn.adafruit.com/assets/assets/000/000/429/original/force___flex_resistanceforce.jpg?1396762946" height="50%" width="50%" >

Source: https://learn.adafruit.com/force-sensitive-resistor-fsr/overview

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**
Yes! Since my output for the force sensor is 0 to 1023 and RGB is 0 to 255 I used.
```
map(forceValue, 0, 1023, 0, 255);
```
**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
Using a 10kOhm resistor worked great, so anything within the range of 10kOhm would be great.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**
Linear realtionship because the more voltage results in more resistance. Ohm's Law!
### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab3/media/output1.png">

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**
As I move my hand closer to the sensor the voltage increases and when I move my had away, it decreases.

**b. Upload your merged code to your lab report repository and link to it here.**
https://github.com/ctcaulfield/Interactive-Lab-Hub/tree/master/labs/lab3/accel_ir

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**
Yes, it does matter what actions are assigned to whichever state. Different states have different actions (in this case: read, write, etc), so it's important to keep their functionality separate.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**
Because we want that code to only run once, whereas when it's in the loop - it is being used continuously.

**c. How many byte-sized data samples can you store on the Atmega328?**
1024 bytes
Source: https://tronixstuff.com/2011/03/16/tutorial-your-arduinos-inbuilt-eeprom/

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**
This can be handled using the function analogRead(x) where x is the pin and using lowByte() and highByte(), I belive this was done in our case via the Wire libary. 

Example code from form:
```
readVal = analogRead(potPin);
Serial.println("read value");
Serial.println(readVal);
byte hiByte = highByte(readVal);
byte loByte = lowByte(readVal);
Serial.println(hiByte,BIN);
Serial.println(loByte,BIN);
```
Source: http://forum.arduino.cc/index.php?topic=72993.0

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**
Using EEPROM.put(address, data) you can store the data if its bigger than a byte. This could prevent duplicates of bytes, hence, creating more space.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**
Link to modified code:
https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab3/modified/modified/modified.ino

### 2. Design your logger
**a. Insert here a copy of your final state diagram.**


<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab3/media/flow.png" height="75%" width="75%" >

### 3. Create your data logger!
**a. Record and upload a short demo video of your logger in action.**
https://youtu.be/9F8ydHaDUPs (Wait until the end, I dropped the ball on my camera! Whoops!)
