# Annie Arduino

This is the Arduino IDE compatible implementation of the Annie library.

## Requirements
This library is intended for use with the Arduino IDE. One can download the IDE from [Arduino's website](https://www.arduino.cc/en/Main/Software).

## Installation
The library files need to go into the `libraries` directory inside Arduino's data diretory. 

On Macs, this is typically located in `Documents/Arduino`.


## Usage

A standard Arduino program consists of two functions: `setup()` and `loop()`.
Setup is called once at the beginning of the program execution.
After `setup()` is done, `loop()` is repeatedly executed until the program ends.

In installed properly, the Annie library commands will be available once you include the header file 
(via `#include "Annie.h"`).

In `setup()`, the user must call `Annie::begin()` at least once.
Without calling `begin()`, the robot will not accept any commands.

The commands are documented in the header file and should be self-explanatory.
Basically, we provide six commands: forward, backward, turn clockwise, turn counterclockwise, read proximity sensor,
and read light sensor.
In addition, we provide "setup" commands to tune the speed of each wheel.

Below is an example code to move the robot forward and backward.
```
#include "Annie.h"

void setup() {
    Annie::begin();
}

void loop() {
    Annie::forward(1000);
    Annie::backward(1000);
    Annie::turnCW(1000);
    Annie::turnCCW(1000);
}
```

## Note on wheel speed calibration
You'll often find that the robot does not move in a straight line even if you haven't changed the default speed settings.
This curving is usually due to the slight differences in the responses of the motors to the same input voltage.
The amount of curvature depends on the individual motors and is not predictable, so we find it best to just leave
that as is for most of our lessons.
You can make the robot go straight by individually tuning the speed of the left and right wheels to compensate
for the differences in the motors.
Done with the students, we find this step to be an instructive exercise in its own right.