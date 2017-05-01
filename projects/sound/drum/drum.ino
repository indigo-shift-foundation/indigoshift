#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {

  int sensorVal2 = digitalRead(2);
  int sensorVal3 = digitalRead(3);

  if (sensorVal2 == HIGH) {
    if (sensorVal3 == HIGH) {
      noTone(8);
    } else {
      tone(8, NOTE_C4, 100);
    }
  } else {
    tone(8, NOTE_G4, 100);
  }
  
}
