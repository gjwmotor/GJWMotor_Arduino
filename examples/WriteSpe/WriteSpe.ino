#include <GJWMotor.h>

GQDMD gqdmd;

void setup()
{
  Serial.begin(115200);
  gqdmd.begin(&Serial1, 115200); // baud-rate at 115200
  gqdmd.setTimeOut(100); // if there is no answer in 100 ms, roll over
  delay(1000);
  gqdmd.WheelMode(1);
  gqdmd.EnableTorque(0, 1);//广播指令打开所有驱动器扭矩开关
}

void loop()
{
  gqdmd.WriteSpe(1, 1000);
  Serial.print("speed:");
  Serial.println(1000);
  delay(6000);

  gqdmd.WriteSpe(1, 0);
  Serial.print("speed:");
  Serial.println(0);
  delay(2000);

  gqdmd.WriteSpe(1, -1000);
  Serial.print("speed:");
  Serial.println(-1000);
  delay(6000);

  gqdmd.WriteSpe(1, 0);
  Serial.print("speed:");
  Serial.println(0);
  delay(2000);
}
