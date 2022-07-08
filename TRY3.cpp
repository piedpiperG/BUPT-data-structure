#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	int	arr[2][2]={1,2,3,4};
	int	brr[2][2];
	memcpy(brr,arr,sizeof(arr));
	for(int	i=0;i<2;i++)
	{
		for(int	j=0;j<2;j++)
		{
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}
}
