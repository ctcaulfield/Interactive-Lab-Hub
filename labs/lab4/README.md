# Paper Puppets

*A lab report by Christopher Caulfield*

## In this Report

To submit your lab, clone [this repository](https://github.com/FAR-Lab/IDD-Fa18-Lab4). You'll need to describe your design, include a video of your paper display in operation, and upload any code you wrote to make it move.

## Part A. Actuating DC motors

**Link to a video of your virbation motor**
https://youtu.be/PFAbpBPhwyQ

## Part B. Actuating Servo motors

### Part 1. Connect the Servo to your breadboard

**a. Which color wires correspond to power, ground and signal?**
Orange = signal, Red = power, Brown = ground

### Part 2. Connect the Servo to your Arduino

**a. Which Arduino pin should the signal line of the servo be attached to?**
```Pin 9```

**b. What aspects of the Servo code control angle or speed?**
There are two main aspects controlling the sweep. First the ```delay()``` function is controlling the speed. Second, within the "for", the max pos value, in this case - 90 handles rotation: 
```
  for (pos = 0; pos <= 90; pos += 1)
``` 

## Part C. Integrating input and output

**Include a photo/movie of your raw circuit in action.**
https://youtu.be/Vf_3-6ouylg

## Part D. Paper puppet

**a. Make a video of your proto puppet.**
https://youtu.be/7rOLj3Sl3b8

## Part E. Make it your own

**a. Make a video of your final design.**
https://youtu.be/TcuZpm6JDW4
 
