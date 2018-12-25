#ifndef Annie_h
#define Annie_h

#include "Arduino.h"

static const int DEFAULT_SPEED = 100;
static const int FRONT = 2;
static const int RIGHT = 3;
static const int LEFT = 4;

class Annie {
public:

    /**
     * Initializes the Arduino. This function must be called once in Arduino's setup() function.
     **/
	static void begin();

    /**
     * Set the speed of both wheels.
     * \param speed An integer between 0 and 200. Note that small numbers (<20) might result in the wheels
     *              not moving at all, depending on the motor's internal friction and battery state.
     **/
	static void setSpeed(int speed);

    /**
     * Set the speed of the left (port side) wheel.
     * \param speed An integer between 0 and 200. Note that small numbers (<20) might result in the wheel
     *              not moving at all, depending on the motor's internal friction and battery state.
     **/
	static void setSpeedLeft(int speed);

    /**
     * Set the speed of the right (starboard side) wheel.
     * \param speed An integer between 0 and 200. Note that small numbers (<20) might result in the wheel
     *              not moving at all, depending on the motor's internal friction and battery state.
     **/
	static void setSpeedRight(int speed);

    /**
     * Move the robot forward until the next command. The robot will continue to move forward until another
     * command tells it to do something else.
     **/
	static void forward();

    /**
     * Move the robot forward for a given milliseconds. The robot will stop after the given milliseconds have elapsed,
     * approximately. Note that this command blocks until the robot stops.
     * \param milliseconds An integer.
     **/
	static void forward(int milliseconds);

    /**
     * Move the robot backward until the next command. The robot will continue to move backward until another
     * command tells it to do something else.
     **/
	static void backward();

    /**
     * Move the robot backward for a given milliseconds. The robot will stop after the given milliseconds have elapsed,
     * approximately. Note that this command blocks until the robot stops.
     * \param milliseconds An integer.
     **/
	static void backward(int milliseconds);

    /**
     * Turn the robot clockwise, looking at it from above. The robot will continue to turn until another command is
     * issued.
     **/
	static void turnCW();

    /**
     * Turn the robot clockwise for a given milliseconds. The robot will stop after the given milliseconds have elapsed,
     * approximately. Note that this command blocks until the robot stops.
     * \param milliseconds An integer.
     **/
	static void turnCW(int milliseconds);

    /**
     * Turn the robot counterclockwise, looking at it from above. The robot will continue to turn until another command is
     * issued.
     **/
	static void turnCCW();

    /**
     * Turn the robot counterclockwise for a given milliseconds. The robot will stop after the given milliseconds have elapsed,
     * approximately. Note that this command blocks until the robot stops.
     * \param milliseconds An integer.
     **/
	static void turnCCW(int milliseconds);

    /**
     * Set the speed of the turn.
     * \param speed An integer between 0 and 200. Note that small numbers (<20) might result in the robot not turning
     *              at all, depending on the motor's internal friction and battery state.
     **/
	static void setSpeedTurn(int speed);

    /**
     * Stop the robot
     **/
	static void stop();

    /**
     * Test whether the proximity sensor has detected an object.
     * \return True if an object is detected, false otherwise.
     **/
    static bool detectsObject();

    /**
     * Test whether the proximity sensor has detected an object. This function is the generic version of detectObject()
     * for sensors that might not be on the standard I/O pin.
     * \param pin An integer value, specifies the pin number to which the sensor is attached.
     * \return True if an object is detected, false otherwise.
     **/
	static bool detectsObject(int pin);

    /**
     * Read the light sensor from a given pin.
     * \param pin An integer value. Note that the standard pin numbers are defined as constants RIGHT and LEFT above.
     * \return The measured intensity value.
     **/
	static int senseLight(int pin);

    /**
     * Internal Functions
     **/
	static void sendSignal(int pin, int signal);
	static bool readDigitalSignal(int pin);
	static int readAnalogSignal(int pin);

private:
	static const int _minSpeed = 0;
	static const int _maxSpeed = 200;
	static int restrain(int value, int min, int max);
};

#endif