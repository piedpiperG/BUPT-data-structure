#include<iostream>
#include<algorithm>
#include<vector>
using	namespace	std;

//����7����Ŀ��ţ�100�ף�0����200�ף�1�������ߣ�2������Զ��3����Ǧ��4����������5������ǹ��6�� 
int	map[]=
{
	0,1,0,1,0,1,0,
	1,0,0,0,0,1,0,
	0,0,0,1,1,0,0,
	1,0,1,0,0,0,1,
	0,0,1,0,0,1,1,
	1,1,0,0,1,0,1,
	0,0,0,1,1,1,0	
}; //��ͼ���飬�洢���Ǹ�����Ŀ֮��Ĺ�ϵ�����������Ŀ����ͬʱ�ٰ죬����Ϊ1 
struct	NODE
{
	int	index;//�ڵ���map�ж�Ӧ��λ��
	int	degree;//���Ķ�
	int	mark;//���ı�� 
};
bool	cmp(NODE	a,NODE	b)
{
	return	a.degree>b.degree;
}//��������������
int	fillcolor(int	map[],int	n);	//�����ɫ���� 
void	callname(int	i);	//ȡ�����ֺ��� 

int	main()
{
	int	n=fillcolor(map,7);
	cout<<"������Ҫ����"<<n<<"���ν��б���"<<endl;
	return	0;
}

int	fillcolor(int	map[],int	n)
{
	int	countMark=0;//��¼��һ��ʹ�õ���ɫ�� 
	vector<int>mark;//��ɫ�ż��� 
	vector<NODE>node;//ͼ�н�㼯�� 
	node.resize(n);
	
	for(int	i=0;i<n;i++)	//ͳ��ͼ��ÿ�����Ķȣ���map������г�ʼ�� 
	{
		node[i].degree=node[i].mark=0;	//�Ⱥͱ�ǳ�ʼ��Ϊ0 
		node[i].index=i;	//���
		for(int	j=0;j<n;j++)
		{
			if(map[i*n+j]==1)
				node[i].degree++;	//��ʼ������	
		} 
	}
	
	sort(node.begin(),node.end(),cmp);//���ն�����������
	
	for(int	i=0;i<n;i++)	//�ӽ�㼯��ȡ����� 
	{
		for(int	j=0;j<mark.size();j++)	//����ɫ����ȡ����ɫ�� 
		{
			//cout<<"mark "<<mark.size()<<endl;
			if(node[node[i].index].mark==0)
				node[node[i].index].mark=mark[j];	//��ɫ
			for(int	k=0;k<n;k++)
			{
				if(map[node[i].index*n+k]==1&&node[k].mark==node[node[i].index].mark)
				{
					node[node[i].index].mark=0;	
				}	
			} 
		}
		if(node[node[i].index].mark==0)	//����һ��ɫ�� 
		{
			mark.push_back((++countMark));
			node[node[i].index].mark=mark.back();
		}
	}
	cout<<"�ڵ�һ��ʱ���ִ�е�������";  
	for(int	i=0;i<7;i++)
	{
		if(node[i].mark==1)
		{
			callname(i); 
		}
	}
	cout<<endl;
	cout<<"�ڵڶ���ʱ���ִ�е�������"; 
	for(int	i=0;i<7;i++)
	{
		if(node[i].mark==2)
		{
			callname(i); 
		}
	}
	cout<<endl;
	cout<<"�ڵ�����ʱ���ִ�е�������"; 
	for(int	i=0;i<7;i++)
	{
		if(node[i].mark==3)
		{
			callname(i);  
		}
	}
	cout<<endl;
	return	countMark;
}


//����7����Ŀ��ţ�100�ף�0����200�ף�1�������ߣ�2������Զ��3����Ǧ��4����������5������ǹ��6��
void	callname(int	i)
{
	if(i==0)
		cout<<"100�� ";
	else	if(i==1)
		cout<<"200�� ";
	else	if(i==2)
		cout<<"���� ";
	else	if(i==3)
		cout<<"��Զ ";
	else	if(i==4)
		cout<<"Ǧ�� ";
	else	if(i==5)
		cout<<"���� ";
	else	if(i==6)
		cout<<"��ǹ ";
}




 
