#include<iostream>
#include<vector>
#include"BalancedTree.h" 
using	namespace	std;
int	main()
{
	int	arr[]={16,3,7,11,9,26,18,14,15};
	BST<int>bt(arr,sizeof(arr)/sizeof(arr[0]));
	vector<int>res;
	res=bt.inorderTraversal(bt.root);	
	for(int	i=0;i<9;i++)
		cout<<res[i]<<" ";
	cout<<endl;
} 
