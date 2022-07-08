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


	cout << "������������������" << endl;
	int	insernum;//��������
	cin >> insernum;
	bt.insertBiNode(bt.root, insernum);
	print(bt);

	cout << "������������ҵ�����" << endl;
	int sernum;//��������
	cin >> sernum;
	if (bt.Search(bt.root, sernum))
		cout << "�鵽" << endl;
	else
		cout << "δ�鵽" << endl;

	cout << "����������ɾ��������" << endl;
	int	delnum;//ɾ������
	cin >> delnum;
	if (bt.DeleteBST(bt.root, delnum))
		cout << "ɾ���ɹ�" << endl;
	else
		cout << "ɾ��ʧ��" << endl;
	print(bt);
	bt.destroy();
	//bt.~BST();
	
}


void	print(BST<int>bt)
{
	cout << "��������Ľ��Ϊ��" << endl;
	vector<int>res;
	res = bt.inorderTraversal(bt.root);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	cout << "��������Ľ��Ϊ��" << endl;
	int conlev = 0;//����
	vector<vector<int>>ret;
	ret = bt.levelOrder(bt.root);
	for (vector<int> i : ret)
	{
		cout << ++conlev << "��" << endl;
		for (int j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "����ƽ������Ϊ��";
	cout << bt.diff(bt.root) << endl;
	cout << endl;
}