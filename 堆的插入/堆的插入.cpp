#include<bits/stdc++.h>
using	namespace	std;

int	Size=10000;




void	Siftup(int	*arr,int	start)
{
	int j = start;
	int i = (j - 1)/2; //i是j的双亲
	int temp = arr[j];
	while(j > 0)
	{
		if(arr[i] >= temp) break;
		else
		{
			//双亲大向下落，继续向上检测 
			arr[j] = arr[i];
			j = i;
			i = (i - 1)/2;
		}
	}
	arr[j] = temp;
}



bool	insert(int	*arr,int	&len,int	x)
{
	if(len==Size)		//堆已满 
		return	false;		
	arr[len]=x;
	Siftup(arr,len);	//向上调整
	len++;
	return	true; 
}





void	Sift(int	r[],int	k,int	m)
{
	int	i=k,j=2*i;
	i--;
	j--;
	while(j<=m)
	{
		if(j<m&&r[j]<r[j+1])
			j++;
		if(r[i]>r[j])
			break;
		else
		{
			int	temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i=j;
			j=2*i;
		}
	}
}

int	main()
{
	int	arr[]={49,38,27,49,76,13,65,97};
	int	n=sizeof(arr)/sizeof(arr[0]);
	for(int	i=n/2;i>=1;i--)
		Sift(arr,i,n);
	cout<<"处理为堆后结果如下"<<endl;
	for(int	i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int	insernum;
	cin>>insernum;
	insert(arr,n,insernum);
	cout<<"插入后结果如下"<<endl;
	for(int	i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

