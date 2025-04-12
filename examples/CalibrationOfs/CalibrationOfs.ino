/*
零位校准例子
*/

#include <GJWMotor.h>

GQDMD gqdmd;

void setup()
{
  Serial.begin(115200);
  gqdmd.begin(&Serial1, 115200);
  gqdmd.setTimeOut(100);
  delay(1000);
  gqdmd.CalibrationOfs(1);
  delay(10);
}

void loop()
{
  int pos = gqdmd.ReadPos(1);
  if(!gqdmd.getLastError()){
    Serial.print("zero pos:");
    Serial.println(pos);
  }
  delay(1000);
}
