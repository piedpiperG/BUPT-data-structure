#include<bits/stdc++.h>
using	namespace	std;
template<class	T,int	N>//����ģ���࣬N��ʾ˳�����󳤶ȣ�ʵ����ʱ���

class	Seplist
{
public:
	Seplist(){length=0;}//�޲ι��캯�� 
	Seplist(T	a[],int	n);//�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��
	int		Getlength(){return	length;}
	void	PrintList();
	void	Insert(int	i,T	x);
	T		Delete(int	i);
	T		Get(int	i);	//��λ���� 
	int		Locate(T	x);//��ֵ���� 
private:
	T	data[N];//����˳�������Ԫ�ص����� 
	int	length;//˳����� 
};

