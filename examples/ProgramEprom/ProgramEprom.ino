#include <GJWMotor.h>

GQDMD gqdmd;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, 5, 4);
  gqdmd.begin(&Serial1);// baud-rate at 1000000
  gqdmd.setTxEnd_T32(1000000);// baud-rate at 1000000
  gqdmd.setTimeOut(100); // if there is no answer in 100 ms, roll over
  delay(1000);
  
  gqdmd.unLockMem(1, GQDMD_COM_ID, 0);//打开EPROM保存功能
  gqdmd.writeReg(1, GQDMD_COM_ID, 2);//ID
  gqdmd.LockMem(2);//关闭EPROM保存功能
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
