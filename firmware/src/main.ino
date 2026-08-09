#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// ================== Settings ==================
enum LanguageMode { ASL, ARSL };
LanguageMode currentLanguage = ARSL;

// ================== Pins ==================
#define THUMB_PIN 1
#define INDEX_PIN 2
#define MIDDLE_PIN 3
#define RING_PIN 4
#define PINKY_PIN 5

// ================== Global ==================
Adafruit_MPU6050 mpu;
bool mpuConnected = false;

int thumb, indexFinger, middle, ring, pinky;
float accX = 0, accY = 0, accZ = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("Tsungu - Data Collection Mode");
  Serial.println(currentLanguage == ASL ? "Language: ASL" : "Language: ARSL");
  Serial.println("Format: thumb,index,middle,ring,pinky,accX,accY,accZ,label");
  Serial.println("================================================");

    if (mpu.begin()) {
      mpuConnected = true;
      mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      Serial.println("MPU6050: Connected");
  } else {
    Serial.println("MPU6050: Not connected");
}

   Serial.println("Ready. Make a gesture and watch the values.");
}

void loop() {
  readSensors();
  printData();
  delay(200);
}

void readSensors() {
  thumb = constrain(map(analogRead(THUMB_PIN), 256, 59, 0, 100), 0, 100);
  indexFinger = constrain(map(analogRead(INDEX_PIN), 256, 59, 0, 100), 0, 100);
  middle = constrain(map(analogRead(MIDDLE_PIN), 256, 59, 0, 100), 0, 100);
  ring = constrain(map(analogRead(RING_PIN), 256, 59, 0, 100), 0, 100);
  pinky = constrain(map(analogRead(PINKY_PIN), 256, 59, 0, 100), 0, 100);

  if (mpuConnected) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    accX = a.acceleration.x;
    accY = a.acceleration.y;
    accZ = a.acceleration.z;
    }
}

void printData() {
  Serial.print(thumb);
  Serial.print(",");
  Serial.print(indexFinger);
  Serial.print(",");
  Serial.print(middle);
  Serial.print(",");
  Serial.print(ring);
  Serial.print(",");
  Serial.print(pinky);
  Serial.print(",");
  Serial.print(accX, 2);
  Serial.print(",");
  Serial.print(accY, 2);
  Serial.print(",");
  Serial.print(accZ, 2);
  Serial.print(",");
  Serial.println("?");
}