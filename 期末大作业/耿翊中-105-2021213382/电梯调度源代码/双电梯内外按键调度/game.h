#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
//#include<iostream>
//using namespace std;
#define length 10  //电梯大小

//1.数据属性：基本数据成员分析
//坐标属性，电梯属性，按键属性

//坐标属性
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;

//电梯属性
struct Lift
{
	int num;//电梯长度
	MYPOINT xy[length]; //电梯最多有10节
	char postion;//电梯的方向
	int curnum = 0;	//梯中人数（待启用）
};
//按键的属性
struct Button
{
	MYPOINT fdxy;	//按键的位置
	int nature ;	//按键的属性（1为上按键，2为下按键，3为电梯内按键）
	int flag = 0;	//按键是否存在，0表示存在，1表示不存在
};

//方向
enum movePostion { right = 77, left = 75, down = 80, up = 72, freeze = 3 };

//主窗口
static HWND hwnd = NULL;


//2.过程分析：函数分析

//初始化主电梯
void initmaiLift(struct Lift*lift);

//初始化副电梯
void initsubLift(struct Lift*lift);

//画电梯
void drawLift(struct Lift* lift);

//移动电梯
void moveLift(struct Lift* lift);

//初始化按键
void initButton(struct Button* button, int x, int y, int na);

//画电梯内部按键
void drawButton(struct Button* button);

//画下按键
void drawdoButton(struct Button* button);

//画上按键
void drawupButton(struct Button* button);

//消去按键
void eatButton(struct Button* button, struct Lift* lift);

//展示提示
void showwords();

//按空格键暂停
void pauseMoment();

//画楼层框架
void drawfloor();

//显示电梯有几人
void showbutton(struct Lift* lift);

//调错函数
void showerror();

//绘制副电梯是否启用
void drawifuse(int x);
