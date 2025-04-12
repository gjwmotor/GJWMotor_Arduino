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
  int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Status;
  int Current;
  
  Pos = gqdmd.ReadPos(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor position:");
    Serial.println(Pos, DEC);
  }else{
    Serial.println("read position err");
  }
  
  Voltage = gqdmd.ReadVoltage(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor Voltage:");
    Serial.println(Voltage, DEC);
  }else{
    Serial.println("read Voltage err");
  }
  
  Temper = gqdmd.ReadTemper(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor temperature:");
    Serial.println(Temper, DEC);
    delay(100);
  }else{
    Serial.println("read temperature err");   
  }

  Speed = gqdmd.ReadISpeed(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor Speed:");
    Serial.println(Speed, DEC);
  }else{
    Serial.println("read Speed err");  
  }
  
  Load = gqdmd.ReadLoad(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor Load:");
    Serial.println(Load, DEC);
  }else{
    Serial.println("read Load err");   
  }
  
  Current = gqdmd.ReadCurrent(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor Current:");
    Serial.println(Current, DEC);

  }else{
    Serial.println("read Current err");  
  }

  Status = gqdmd.ReadStatus(1);
  if(!gqdmd.getLastError()){
    Serial.print("Motor Status:");
    Serial.println(Status, DEC);
  }else{
    Serial.println("read Status err");   
  }

  if(!gqdmd.getLastError()){
    delay(500);
  }else{
    delay(500);
  }
  Serial.println();
}
