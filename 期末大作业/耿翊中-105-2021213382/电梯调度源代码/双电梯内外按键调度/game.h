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
#define length 10  //���ݴ�С

//1.�������ԣ��������ݳ�Ա����
//�������ԣ��������ԣ���������

//��������
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;

//��������
struct Lift
{
	int num;//���ݳ���
	MYPOINT xy[length]; //���������10��
	char postion;//���ݵķ���
	int curnum = 0;	//���������������ã�
};
//����������
struct Button
{
	MYPOINT fdxy;	//������λ��
	int nature ;	//���������ԣ�1Ϊ�ϰ�����2Ϊ�°�����3Ϊ�����ڰ�����
	int flag = 0;	//�����Ƿ���ڣ�0��ʾ���ڣ�1��ʾ������
};

//����
enum movePostion { right = 77, left = 75, down = 80, up = 72, freeze = 3 };

//������
static HWND hwnd = NULL;


//2.���̷�������������

//��ʼ��������
void initmaiLift(struct Lift*lift);

//��ʼ��������
void initsubLift(struct Lift*lift);

//������
void drawLift(struct Lift* lift);

//�ƶ�����
void moveLift(struct Lift* lift);

//��ʼ������
void initButton(struct Button* button, int x, int y, int na);

//�������ڲ�����
void drawButton(struct Button* button);

//���°���
void drawdoButton(struct Button* button);

//���ϰ���
void drawupButton(struct Button* button);

//��ȥ����
void eatButton(struct Button* button, struct Lift* lift);

//չʾ��ʾ
void showwords();

//���ո����ͣ
void pauseMoment();

//��¥����
void drawfloor();

//��ʾ�����м���
void showbutton(struct Lift* lift);

//������
void showerror();

//���Ƹ������Ƿ�����
void drawifuse(int x);
