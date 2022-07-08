#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
class Elevator
{
private:
	int currentFloor;     //��������λ��
public:
	Elevator(int cfloor=1);      //���캯��
	void request(int newfloor);
};
 
Elevator::Elevator(int cfloor)
{
	currentFloor=cfloor;
}
void Elevator::request(int newfloor)
{
	if(newfloor==currentFloor)
	{
		cout<<"You have on the floor!!!"<<endl;
		return;
	}
	else if(newfloor>currentFloor)   //���������ƶ�
	{
		cout<<endl<<"Starting at floor......"<<currentFloor<<endl;
		while(newfloor>currentFloor)
		{
			currentFloor++;
			Sleep(2000);
			cout<<"Going up-now at floor.."<<currentFloor<<endl;
		}
		cout<<"Stopping at floor......"<<currentFloor<<endl;
	}
	else       //���������ƶ�
	{
		cout<<endl<<"Starting at floor........"<<currentFloor<<endl;
		while(newfloor<currentFloor)
		{
			currentFloor--;
			Sleep(2000);
			cout<<"Going down-now at floor.."<<currentFloor<<endl;
		}
		cout<<"Stopping at floor........"<<currentFloor<<endl;
	}
}
 
int main()
{
	char answer='y';
	int aimfloor=0;     //Ŀ�����
	Elevator a;
	while(answer!='n')
	{
		cout<<"please input your floor(1--15):";
		cin>>aimfloor;
		if(aimfloor<1||aimfloor>15)
		{
			cout<<"*****Floor is wrong!!!*****"<<endl;
		}
		else
		{
			a.request(aimfloor);
		}
		cout<<endl<<"You go on?(y or n):";
		cin>>answer;
	}
	cout<<"Thank you for using!!!"<<endl;
	system("pause");
	return 0;
}
