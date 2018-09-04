# IDD-Fa18-Lab1: Blink!

**A lab report by Christopher Caulfield*

## Part A. Set Up a Breadboard
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab1/media/board.png" height="50%" width="50%" >

## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**
Forgive me, I am very color blind, but I believe the colors are: Red, Red, Black, Black, Brown
 
**b. What do you have to do to light your LED?**
To light my LED I needed to create a circuit similar to shown: [here]https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/blob/docs/button_led_resistor_diagram.png. Connecting a button is the trigger point for the LED to light up.

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
When I set the delay around 20 milliseconds, it became difficult to visually see it was still blinking. The way I prove myself is by knowing I have a delay() function set meaning it's still technically blinking!

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**
[Link to repository]https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab1/lab1_partC/lab1_partC.ino

### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

YouTube demo of blinking LED:[here]https://www.youtube.com/watch?v=cBjIbLcMPrw&feature=youtu.be


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**
Yes, turning the "wiper" determines how much resistence is being genereated to the circuit.
<img src="https://i0.wp.com/rntlab.com/wp-content/uploads/2016/02/Fig.-4.png?zoom=2&resize=460%2C181&ssl=1" height="50%" width="50%" >

Source: https://randomnerdtutorials.com/electronics-basics-how-a-potentiometer-works/

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**
All code is the same, the only important chance to make is   ```analogWrite(led, random(1, 255));```

```
int led = 3;           // the PWM pin the LED is attached to

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 3 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //set brightness value to random  
  analogWrite(led, random(1, 255));
  delay(1000);
}
```
YouTube demo of fade using Arduino:[here]https://www.youtube.com/watch?v=NJVencvOdQg&feature=youtu.be

**b. What is analogWrite()? How is that different than digitalWrite()?**
analogWrite() writes a "Pulse-Width Modulated" (PWM) wave signal to a pin, providing varying brightnesses. On the other hand digitalWrite() sets the pin to a HIGH or LOW value at stays at that.

Sources:
digitalWrite() documentation: https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/
analogWrite() documentation: https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 
For my device I decided to take apart an old bluetooth audio reciever!
*Important Note - I meant to write microcontroller instead of microprocessor!* 
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab1/media/diagram.jpg" height="50%" width="50%" >

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**
There is computation happening inside - within the microcontroller. It recieves audio from a paired bluetooth device and sends it through a headset which requires an AUX input. The device also has a microphone so it recieves sound and sends the audio to the paired device via bluetooth.

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**
There are 5 buttons on the device. For skip, go back, pause play, volume up, and volume down. When the user clicks on a button it triggered to the microcontroller.  

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**
The device is powered via a micro USB port. The devices contains a small battery which holds the provided power from the micro USB. The voltage used throughout the system is 1.5V. 

**d. Is information stored in your device? Where? How?**
I believe information is stored on the device and this is held within the microcontroller's RAM. Information is send to the microcontroller via bluetooth, which can then be stored.

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**
The device already contains an LED, but this did not stop me from adding another one. Unfortunately, the device is very compact and it is hard to attach additional items. Thankfully I was able to get the right circuit by connecting the LED directly ontop of the current LED.

### 3. Build your light!

Demo of Frankenlight:[here]https://www.youtube.com/watch?v=2aChkfvMSjs&feature=youtu.be
