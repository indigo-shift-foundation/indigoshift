#include "Arduino.h"
#include "Annie.h"

static int _speedLeft;
static int _speedRight;
static int _speedTurn;

static int _leftDirectionPin2 = 6;
static int _leftDirectionPin1 = 7;
static int _leftSpeedPin = 5;

static int _rightDirectionPin1 = 9;
static int _rightDirectionPin2 = 10;
static int _rightSpeedPin = 11;

void Annie::begin() {
	//direction left
	pinMode(_leftDirectionPin2, OUTPUT);
	pinMode(_leftDirectionPin1, OUTPUT);

	//speed left
	pinMode(_leftSpeedPin, OUTPUT);

	//direction right
	pinMode(_rightDirectionPin1, OUTPUT);
	pinMode(_rightDirectionPin2, OUTPUT);

	//speed right
	pinMode(_rightSpeedPin, OUTPUT);

	//proximity sensing
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);

	//loop until A0 pulled down
	pinMode(A0, INPUT_PULLUP);
	while(digitalRead(A0) == HIGH) {}
	delay(500);
}

void Annie::sendSignal(int pin, int signal) {
	if(pin == 3 || pin == 5 || pin == 6 || pin == 9 || pin == 10 || pin == 11) {
		int adjustedSignal = Annie::restrain(signal, _minSpeed, _maxSpeed);
		analogWrite(pin, adjustedSignal);
	} else {
		digitalWrite(pin, signal > 0 ? HIGH : LOW);
	}
}

bool Annie::readDigitalSignal(int pin) {
	return digitalRead(pin);
}

int Annie::readAnalogSignal(int pin) {
	return analogRead(pin);
}

void Annie::setSpeed(int speed) {
	_speedLeft = speed;
	_speedRight = speed;
	_speedTurn = speed;
}

void Annie::setSpeedLeft(int speed) {
	_speedLeft = speed;
}

void Annie::setSpeedRight(int speed) {
	_speedRight = speed;
}

void Annie::setSpeedTurn(int speed) {
	_speedTurn = speed;
}

void Annie::forward() {
	Annie::sendSignal(_leftDirectionPin1, 255);
	Annie::sendSignal(_leftDirectionPin2, 0);
	Annie::sendSignal(_leftSpeedPin, _speedLeft);

	Annie::sendSignal(_rightDirectionPin1, 0);
	Annie::sendSignal(_rightDirectionPin2, 255);
	Annie::sendSignal(_rightSpeedPin, _speedRight);
}

void Annie::forward(int milliseconds) {
	Annie::forward();
	delay(milliseconds);
	Annie::stop();
}

void Annie::backward() {
	Annie::sendSignal(_leftDirectionPin1, 0);
	Annie::sendSignal(_leftDirectionPin2, 255);
	Annie::sendSignal(_leftSpeedPin, _speedLeft);

	Annie::sendSignal(_rightDirectionPin1, 255);
	Annie::sendSignal(_rightDirectionPin2, 0);
	Annie::sendSignal(_rightSpeedPin, _speedRight);
}

void Annie::backward(int milliseconds) {
	Annie::backward();
	delay(milliseconds);
	Annie::stop();
}

void Annie::turnCW() {
	Annie::sendSignal(_leftDirectionPin1, 255);
	Annie::sendSignal(_leftDirectionPin2, 0);
	Annie::sendSignal(_leftSpeedPin, _speedLeft);

	Annie::sendSignal(_rightDirectionPin1, 255);
	Annie::sendSignal(_rightDirectionPin2, 0);
	Annie::sendSignal(_rightSpeedPin, _speedRight);
}

void Annie::turnCW(int milliseconds) {
	Annie::turnCW();
	delay(milliseconds);
	Annie::stop();
}

void Annie::turnCCW() {
	Annie::sendSignal(_leftDirectionPin1, 0);
	Annie::sendSignal(_leftDirectionPin2, 255);
	Annie::sendSignal(_leftSpeedPin, _speedLeft);

	Annie::sendSignal(_rightDirectionPin1, 0);
	Annie::sendSignal(_rightDirectionPin2, 255);
	Annie::sendSignal(_rightSpeedPin, _speedRight);
}

void Annie::turnCCW(int milliseconds) {
	Annie::turnCCW();
	delay(milliseconds);
	Annie::stop();
}

void Annie::stop() {
	Annie::sendSignal(_leftSpeedPin, 0);
	Annie::sendSignal(_rightSpeedPin, 0);
}

void Annie::stop(int milliseconds) {
	Annie::stop();
	delay(milliseconds);
}

bool Annie::detectsObject() {
	return Annie::readDigitalSignal(FRONT) == 0;
}

bool Annie::detectsObject(int pin) {
	return Annie::readDigitalSignal(pin) == 0;
}

int Annie::senseLight() {
	return Annie::senseLight(FRONT);
}

int Annie::senseLight(int pin) {
	return Annie::readAnalogSignal(pin);
}


int Annie::restrain(int value, int min, int max) {
	int limitedValue = value;
	if(limitedValue > max) {
		limitedValue = max;
	} else if(limitedValue < min) {
		limitedValue = min;
	}
	return limitedValue;
}