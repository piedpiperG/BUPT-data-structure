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
#define length 100  //蛇长度

//1.数据分析：基本数据成员分析
//坐标属性，蛇属性，食物属性

//坐标属性
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;

//蛇属性
struct Snake
{
	int num;//蛇的节数
	MYPOINT xy[length]; //蛇最多有100节
	char postion;//蛇的方向
	int curnum=0;	//梯中人数
};
//食物的属性
struct Food
{
	MYPOINT fdxy;
	int eatgrade = 0;//吃食物的分数
	int flag = 0;//食物是否存在，0表示存在，1表示不存在
};
//方向
enum movePostion { right = 77, left = 75, down = 80, up = 72, freeze = 3 };

//主窗口
static HWND hwnd = NULL;

//2.过程分析：函数分析
//初始化蛇和食物
void initSnakeFood(struct Snake*snake, struct Food* food);
//画蛇
void drawSnake(struct Snake* snake);
//移动蛇
void moveSnake(struct Snake* snake);
//按键处理
void keyDown(struct Snake* snake);
//初始化食物
void initFood(struct Food*food, struct Snake* snake, int x, int y);
//画食物
void drawFood(struct Food* food);

//吃食物
void eatFood(struct Food* food, struct Snake* snake);

//判断是否游戏结束
int snakeDie(struct Snake* snake);

//判断游戏是否胜利
int winGame(struct Snake* snake);

//展示分数
void showGrade(struct Food* food);

//按空格键暂停
void pauseMoment();

//画楼层框架
void drawfloor();

//显示电梯有几人
void showfood(struct Snake* snake);

//调错函数
void showerror();