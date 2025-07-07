#include <MPU6050_tockn.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
void setup() {
  Serial.begin (9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X: ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("Angle Y: ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("Angle Z: ");
  Serial.println(mpu6050.getAngleZ());
}
