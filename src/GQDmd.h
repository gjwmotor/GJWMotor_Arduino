/*
 * GQDmd.h
 * GJW驱动应用层程序
 * 日期: 2025.04.12
 * 作者: txl
 */

#ifndef _GQDMD_H
#define _GQDMD_H


//内存表定义
#define GQDMD_GOAL_POSITION (1*64+2)
#define GQDMD_GOAL_ACC (1*64+4)
#define GQDMD_GOAL_SPEED (1*64+5)
#define GQDMD_FAULT_RESET (1*64+8)
#define GQDMD_TORQUE_ENABLE (1*64+9)

#define GQDMD_PRESENT_POSITION (2*64+2)
#define GQDMD_PRESENT_ESPEED (2*64+6)
#define GQDMD_PRESENT_ISPEED (2*64+7)
#define GQDMD_PRESENT_CURRENT (2*64+8)
#define GQDMD_PRESENT_VOLTAGE (2*64+9)
#define GQDMD_PRESENT_TEMPERATURE (2*64+10)
#define GQDMD_PRESENT_LOAD (2*64+11)
#define GQDMD_PRESENT_ERROR (2*64+12)

#define GQDMD_COM_ID (3*64+0)

#define GQDMD_MODE (4*64+0)

//重置电机状态宏
#define GQDMD_FAULT_OFS (1<<15)

#include "modbus.h"

class GQDMD : public Modbus
{
public:
	GQDMD();
	int WritePos(uint8_t ID, int32_t Position, uint16_t ACC, uint16_t Speed);//写位置指令
	int WritePos(uint8_t ID, int32_t Position);//写位置指令
	int WriteSpe(uint8_t ID, int16_t Speed, uint16_t ACC);//恒速模式控制指令
	int WriteSpe(uint8_t ID, int16_t Speed);//恒速模式控制指令
	int WriteMode(uint8_t ID, uint16_t Mode);//模式切换
	void WheelMode(uint8_t ID);//恒速模式切换
	void ServoMode(uint8_t ID);//伺服模式切换
	int EnableTorque(uint8_t ID, uint8_t Enable);//扭力控制指令
	int unLockMem(uint8_t ID, uint16_t Lock, uint16_t Key);//eprom解锁
	int LockMem(uint8_t ID);//eprom加锁
	int CalibrationOfs(uint8_t ID);//中位校准
	int32_t ReadPos(int ID);//读位置
	int ReadISpeed(int ID);
	int ReadESpeed(int ID);
	void WritePosEx(uint8_t ID, int32_t Position);
	void WritePosEx(uint8_t ID, int32_t Position, uint16_t ACC, uint16_t Speed);
	void SyncWritePos(uint8_t ID, int32_t Position);
	int ReadVoltage(int ID);//读电压
	int ReadTemper(int ID);//读温度
	int ReadStatus(int ID);//读状态
	int ReadCurrent(int ID);//读电流
	int ReadLoad(int ID);//读输出扭力
	int SpeedCtl(int ID, int16_t Speed, int16_t ACC, int16_t Torque, int16_t beatTime, uint8_t Ack = 1);//速度控制指令
	int PositionCtl(int ID, int32_t Position, int16_t Speed, int16_t ACC, int16_t Torque, uint8_t Ack = 1);//位置控制指令
	int TorqueCtl(int ID, int16_t Torque, int16_t beatTime, uint8_t Ack = 1);//扭矩控制指令
	int SetpCtl(int ID, int32_t Setp, int16_t Speed, int16_t ACC, int16_t Torque, uint8_t Ack = 1);//步进控制指令
	int ReadStatus(int ID, uint16_t rstErr);//驱动状态反馈
public:
	int32_t motorTurn;
	int16_t motorSpeed;
	int16_t motorAngle;
	int16_t motorTorque;
	uint16_t motorStatus;
};

#endif