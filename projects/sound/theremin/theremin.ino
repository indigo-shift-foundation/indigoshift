#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    int freq = pow(2, measure.RangeMilliMeter / 50.0) * 10 + 80;
    Serial.print("Distance (mm): "); Serial.println(freq);
    if (freq > 100) {
      tone(8, freq, 100);
    } else {
      noTone(8);
    }
  } else {
    Serial.println(" out of range ");
  }

}
