#include <GJWMotor.h>

GQDMD gqdmd;

void setup() {
  gqdmd.begin(&Serial1, 115200);
  gqdmd.setTimeOut(100);
  delay(1000);
  gqdmd.EnableTorque(0, 1);//广播指令打开所有驱动器扭矩开关
  gqdmd.setFlush(0);//打开发送缓存功能，必需调用flushTx()才能将缓冲指令发送
}

void loop() {
  //put your main code here, to run repeatedly: 
  gqdmd.SyncWritePos(1, -32768);//驱动器(ID1)以默认速度运行至-32768位置
  gqdmd.SyncWritePos(2, -32768);//驱动器(ID2)以默认速度运行至-32768位置
  gqdmd.actionSync(0);//广播发送同步执行指令
  gqdmd.flushTx();//刷新发送缓冲区，所有驱动器接收指令后同步运行
  delay(1000);//延时足够时间

  gqdmd.SyncWritePos(1, 32767);//驱动器(ID1)以默认速度运行至32767位置
  gqdmd.SyncWritePos(2, 32767);//驱动器(ID2)以默认速度运行至32767位置
  gqdmd.actionSync(0);//广播发送同步执行指令
  gqdmd.flushTx();//刷新发送缓冲区，所有驱动器接收指令后同步运行
  delay(1000);//延时足够时间
}

