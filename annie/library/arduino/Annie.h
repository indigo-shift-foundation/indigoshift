#ifndef Annie_h
#define Annie_h

#include "Arduino.h"

static const int FRONT = 2;
static const int RIGHT = 3;
static const int LEFT = 4;

class Annie {
public:
	static void begin();

	static void sendSignal(int pin, int signal);
	static bool readDigitalSignal(int pin);
	static int readAnalogSignal(int pin);

	static void setSpeed(int speed);
	static void setSpeedLeft(int speed);
	static void setSpeedRight(int speed);
	static void setSpeedTurn(int speed);

	static void forward();
	static void forward(int milliseconds);
	static void backward();
	static void backward(int milliseconds);

	static void turnCW();
	static void turnCW(int milliseconds);
	static void turnCCW();
	static void turnCCW(int milliseconds);

	static void stop();
	static void stop(int milliseconds);

	static bool detectsObject();
	static bool detectsObject(int pin);
	static int senseLight();
	static int senseLight(int pin);

private:
	static const int _minSpeed = 0;
	static const int _maxSpeed = 200;
	static int restrain(int value, int min, int max);
};

#endif