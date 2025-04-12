#include <GJWMotor.h>

GQDMD gqdmd;

void setup()
{
  Serial.begin(115200);
  gqdmd.begin(&Serial1, 115200);
  gqdmd.setTimeOut(100);
  delay(1000);
}

void loop()
{
  int ID = gqdmd.Ping(0);
  if(!gqdmd.getLastError()){
    Serial.print("slave ID:");
    Serial.println(ID, DEC);
    delay(200);
  }else{
    Serial.print("last error:");
    Serial.println(gqdmd.getLastError());
    delay(2000);
  }
}
