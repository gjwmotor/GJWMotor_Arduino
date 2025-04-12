#include <GJWMotor.h>

GQDMD gqdmd;

void setup()
{
  Serial.begin(115200);
  gqdmd.begin(&Serial1, 1000000, SERIAL_8N1, 5, 4); // baud-rate at 1000000
  gqdmd.setTimeOut(100); // if there is no answer in 100 ms, roll over
  delay(1000);
}

void loop()
{
  gqdmd.SpeedCtl(1, 1000, 500, 600, 0);
  if(!gqdmd.getLastError()){
    Serial.println(gqdmd.motorTurn);
    Serial.println(gqdmd.motorAngle);
    Serial.println(gqdmd.motorSpeed);
    Serial.println(gqdmd.motorTorque);
    Serial.println(gqdmd.motorStatus);
  }
  delay(6000);

  gqdmd.SpeedCtl(1, 0, 500, 600, 0);
  if(!gqdmd.getLastError()){
    Serial.println(gqdmd.motorTurn);
    Serial.println(gqdmd.motorAngle);
    Serial.println(gqdmd.motorSpeed);
    Serial.println(gqdmd.motorTorque);
    Serial.println(gqdmd.motorStatus);
  }
  delay(2000);

  gqdmd.SpeedCtl(1, -1000, 500, 600, 0);
  if(!gqdmd.getLastError()){
    Serial.println(gqdmd.motorTurn);
    Serial.println(gqdmd.motorAngle);
    Serial.println(gqdmd.motorSpeed);
    Serial.println(gqdmd.motorTorque);
    Serial.println(gqdmd.motorStatus);
  }
  delay(6000);

  gqdmd.SpeedCtl(1, 0, 500, 600, 0);
  if(!gqdmd.getLastError()){
    Serial.println(gqdmd.motorTurn);
    Serial.println(gqdmd.motorAngle);
    Serial.println(gqdmd.motorSpeed);
    Serial.println(gqdmd.motorTorque);
    Serial.println(gqdmd.motorStatus);
  }
  delay(2000);
}
