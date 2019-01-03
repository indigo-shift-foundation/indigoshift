# Annie Hardware

The robot is a basic programmable car with two controllable wheels, a proximity sensor facing forward, and two light sensors 
facing down.

![The Robot](/annie/images/annie_assembled_0.jpg)

## Parts
Below is a table of the parts that make up the robot in the current version.

| Item                 | ~Cost/Unit | Quantity | Total  | Source                                                                                                                                                                                                 | Notes                                                           |
|----------------------|---------------|----------|--------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------|
| Arduino Uno          | $20.00        | 1        | $20.00 | [Amazon Link](https://smile.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_3?ie=UTF8&qid=1545691164&sr=8-3&keywords=arduino+uno+r3+A000066)                                                                     | cheaper knockoffs available at 50% discount                     |
| Arduino Protoshield  | $8.00         | 1        | $8.00  | [Amazon Link](https://smile.amazon.com/Wangdd22-Prototype-Expansion-Breadboard-ProtoShield/dp/B00I0R9Z56/ref=sr_1_1?ie=UTF8&qid=1545691542&sr=8-1&keywords=Wangdd22+UNO+Proto+Shield+Prototype) | comes with mini breadboard                                      |
| DC Motor Driver      | $4.95         | 1        | $4.95  | [Adafruit Link](https://www.adafruit.com/products/2448)                                                                                                                                                                 | 1.2A DC/Stepper driver, supports two motors                     |
| Robot Chassis Kit    | $24.95        | 1        | $24.95 | [Adafruit Link](https://www.adafruit.com/products/2939)                                                                                                                                                                 | chassis, mounting plate, 2 wheels, 2 DC motors, 1 support wheel |
| 4x AA Battery Holder | $2.95         | 1        | $2.95  | [Adafruit Link](https://www.adafruit.com/products/830)                                                                                                                                                                 | on/off switch, power/ground wires                               |
| AA batteries         | $0.24         | 4        | $0.96  | [Amazon Link](http://www.amazon.com/AmazonBasics-Performance-Alkaline-Batteries-48-Pack/dp/B00MNV8E0C/ref=sr_1_1_a_it?ie=UTF8&qid=1461864065&sr=8-1&keywords=aa+batteries)                                            | 48-pack                                                         |
| Jumper wires         | $0.10         | 10       | $1.00  | [Adafruit Link](https://www.adafruit.com/products/758)                                                                                                                                                                  | 3.95 for 40                                                     |
| USB cable            | $3.95         | 1        | $3.95  | [Adafruit Link](https://www.adafruit.com/products/62)                                                                                                                                                                   |                                                                 |
| Resistors            | $2.00         | 1        | $2.00  |                                                                                                                                                                                                        |                                                                 |
| Photo transistor     | $0.95         | 2        | $1.90  | [Adafruit Link](https://www.adafruit.com/products/2831)                                                                                                                                                                 | Light sensor                                                    |
| Proximity sensor     | $6.95         | 1        | $6.95  | [Adafruit Link](https://www.adafruit.com/products/1927)                                                                                                                                                                 | Proximity sensor                                                |
| Velcro pads          | $1.00         | 1        | $1.00  |                                                                                                                                                                                                        | For attaching the battery pack                                  |
| Misc hardware        | $1.00         | 1        | $1.00  |                                                                                                                                                                                                        | Screws and nuts for anchoring Arduino to chassis                |

### Arduino Uno
The Arduino Uno is the brain of the robot. We think that the Uno offers the right balance of capabilities and affordability for project like ours.
We like to pair the Uno with a protoshield for added flexibility and working space, though strictly speaking this is optional.
The protoshield also comes with a mini breadboard that makes it easy to change the wiring of the robot safely, as we've often
found that young students and soldering don't mix well.

### Chassis Kit
Our friends at Adafruid have put together a convenient chassis kit that includes a chassis, two wheels and 2 DC motors to power the wheels.
We find that the kit is a perfect base on which to build a self-contained robot.

### DC Motor Driver
The Arduino Uno on its own does not have enough oomph to power the two DC motors that come with the chassis kit.
So, we need this DC motor driver to drive the motors at reasonable speeds. There are Arduino shield that incorporate
motor drivers ([like this one](https://www.adafruit.com/product/1438)), but we find that the additional cost is not justifiable
for curricula like ours.

### Sensors

The robot has three sensors: two light sensors facing down, and one proximity sensor facing forward.

The two light sensors are photo transistor sensors that induce current to flow when light hits.
These sensors are analog sensors that are reasonably precise and affordable. The current that these sensors
induce can be a bit too much for the analog I/O pin of an Arduino Uno, so it's best to put a resistor (few hundred ohms)
between the sensor and the pin.

The proximity sensor is a IR reflection sensor that measures "distance" by emitting IR radiation and measuring
the intensity of the reflection of the radiation. It is a digital sensor and is not really designed to 
accurately measure the physical distance to an object, but can tell reasonably well if there is an object
nearby. Because of the nature of how it works, the sensor will have hard time detecting objects that do
not reflect IR well (non-metalic black surfaces).

### Battery Pack
We find that 4 AA batteries in series work well for this setup. With 1.5V each (alkaline batteries), 
the nominal 6V total is just about perfect for the 5V circuitry of the Arduino Uno. 

### Other Parts
The other parts listed are miscellaneous parts that are used to glue together the robot. 

## Assembly

To be added.

If you need assistance in assembling the robots, or would like to receive pre-assembled robots, please contact us at <support@indigoshift.org>.
We will be happy to help.