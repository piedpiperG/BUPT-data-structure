#include<iostream>
#include<vector>
#include"BalancedTree.h" 
using	namespace	std;

void	print(BST<int>bt);
int	main()
{
	int	arr[] = { 13,24,37,90,53 };
	//3,7,9,11,15,14,16,18,26
	int	n = sizeof(arr) / sizeof(arr[0]);
	BST<int>bt(arr,n);

	print(bt);


	cout << "请输入你想插入的数字" << endl;
	int	insernum;//插入数字
	cin >> insernum;
	bt.insertBiNode(bt.root, insernum);
	print(bt);

	cout << "请输入你想查找的数字" << endl;
	int sernum;//查找数字
	cin >> sernum;
	if (bt.Search(bt.root, sernum))
		cout << "查到" << endl;
	else
		cout << "未查到" << endl;

	cout << "请输入你想删除的数字" << endl;
	int	delnum;//删除数字
	cin >> delnum;
	if (bt.DeleteBST(bt.root, delnum))
		cout << "删除成功" << endl;
	else
		cout << "删除失败" << endl;
	print(bt);
	bt.destroy();
	//bt.~BST();
	
}


void	print(BST<int>bt)
{
	cout << "中序遍历的结果为：" << endl;
	vector<int>res;
	res = bt.inorderTraversal(bt.root);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	cout << "层序遍历的结果为：" << endl;
	int conlev = 0;//层数
	vector<vector<int>>ret;
	ret = bt.levelOrder(bt.root);
	for (vector<int> i : ret)
	{
		cout << ++conlev << "层" << endl;
		for (int j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "树的平衡因子为：";
	cout << bt.diff(bt.root) << endl;
	cout << endl;
}