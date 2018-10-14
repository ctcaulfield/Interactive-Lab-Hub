# Useless Box

## 3D Printing

**Printed Part**
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab5/media/bop.jpeg">

## Laser Cutting

**See photo of box in Portable Photo Studio**


## Electronics

**Circuit**
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab5/media/IMG_6188.jpeg">


## Putting it All Together

Include here:
1. Your Arduino code.
```
#include <Servo.h> 

#define servoPin  10
#define switchPin 2

#define closePos  0
#define openPos   180

Servo servo;
int switchState;
int previousSwitchState;

// call this when the input on pin 2 changes (LOW to HIGH *or* HIGH to LOW)
void ToggleSwitch(int switchState)
{    
  if (switchState == HIGH)
  {
    servo.write(closePos);
    //Serial.println("switch state is HIGH.  servo.write(openPos) called to open useless box");
  }
  else
  {
    servo.write(openPos);
    //Serial.println("switch state is LOW.   servo.write(closePos) called to close useless box");
  }
  previousSwitchState = switchState;  // remember that the switch state has changed 
}

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Useless Box Lab 5");

  // start with the box closed and the switch in the off postion
  switchState = LOW;
  previousSwitchState = LOW;

  // connect to our servo and make sure it is in the closed position
  servo.attach(servoPin);
  servo.write(closePos);

  // we should probably pay attention to the switch
  pinMode(switchPin, INPUT); 
}

void loop()
{ 
  int switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState)
    ToggleSwitch(switchState);

  delay(20);
}
```


1. `.stl` or `.svg` files for your "bopper" — if you use some other technique, include the respective supporting material.
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab5/media/output1.png">

1. At least one photo of your useless box taken in the MakerLab's Portable Photo Studio (or somewhere else, but of similar quality).
<img src="https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab5/media/IMG_6187.jpeg">

1. A video of your useless box in action.
https://github.com/ctcaulfield/Interactive-Lab-Hub/blob/master/labs/lab5/media/IMG_6172.mov
