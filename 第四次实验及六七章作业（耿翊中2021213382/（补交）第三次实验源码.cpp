#include<iostream>
#include<algorithm>
#include<vector>
using	namespace	std;

//将这7个项目编号，100米（0）、200米（1）、跳高（2）、跳远（3）、铅球（4）、铁饼（5），标枪（6） 
int	map[]=
{
	0,1,0,1,0,1,0,
	1,0,0,0,0,1,0,
	0,0,0,1,1,0,0,
	1,0,1,0,0,0,1,
	0,0,1,0,0,1,1,
	1,1,0,0,1,0,1,
	0,0,0,1,1,1,0	
}; //地图数组，存储的是各个项目之间的关系，如果两个项目不能同时举办，则标记为1 
struct	NODE
{
	int	index;//节点在map中对应的位置
	int	degree;//结点的度
	int	mark;//结点的标记 
};
bool	cmp(NODE	a,NODE	b)
{
	return	a.degree>b.degree;
}//按度数降序排列
int	fillcolor(int	map[],int	n);	//填充颜色函数 
void	callname(int	i);	//取出名字函数 

int	main()
{
	int	n=fillcolor(map,7);
	cout<<"最少需要安排"<<n<<"场次进行比赛"<<endl;
	return	0;
}

int	fillcolor(int	map[],int	n)
{
	int	countMark=0;//记录第一个使用的颜色号 
	vector<int>mark;//颜色号集合 
	vector<NODE>node;//图中结点集合 
	node.resize(n);
	
	for(int	i=0;i<n;i++)	//统计图中每个结点的度，对map数组进行初始化 
	{
		node[i].degree=node[i].mark=0;	//度和标记初始化为0 
		node[i].index=i;	//编号
		for(int	j=0;j<n;j++)
		{
			if(map[i*n+j]==1)
				node[i].degree++;	//初始化度数	
		} 
	}
	
	sort(node.begin(),node.end(),cmp);//按照度数降序排列
	
	for(int	i=0;i<n;i++)	//从结点集中取出结点 
	{
		for(int	j=0;j<mark.size();j++)	//从颜色集中取出颜色号 
		{
			//cout<<"mark "<<mark.size()<<endl;
			if(node[node[i].index].mark==0)
				node[node[i].index].mark=mark[j];	//着色
			for(int	k=0;k<n;k++)
			{
				if(map[node[i].index*n+k]==1&&node[k].mark==node[node[i].index].mark)
				{
					node[node[i].index].mark=0;	
				}	
			} 
		}
		if(node[node[i].index].mark==0)	//新增一个色号 
		{
			mark.push_back((++countMark));
			node[node[i].index].mark=mark.back();
		}
	}
	cout<<"在第一个时间段执行的任务有";  
	for(int	i=0;i<7;i++)
	{
		if(node[i].mark==1)
		{
			callname(i); 
		}
	}
	cout<<endl;
	cout<<"在第二个时间段执行的任务有"; 
	for(int	i=0;i<7;i++)
	{
		if(node[i].mark==2)
		{
			callname(i); 
		}
	}
	cout<<endl;
	cout<<"在第三个时间段执行的任务有"; 
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


//将这7个项目编号，100米（0）、200米（1）、跳高（2）、跳远（3）、铅球（4）、铁饼（5），标枪（6）
void	callname(int	i)
{
	if(i==0)
		cout<<"100米 ";
	else	if(i==1)
		cout<<"200米 ";
	else	if(i==2)
		cout<<"跳高 ";
	else	if(i==3)
		cout<<"跳远 ";
	else	if(i==4)
		cout<<"铅球 ";
	else	if(i==5)
		cout<<"铁饼 ";
	else	if(i==6)
		cout<<"标枪 ";
}




 
