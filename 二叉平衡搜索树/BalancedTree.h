#include<iostream>
#include<vector> 
#include<algorithm>
#include<queue>
using	namespace	std;

template<class	T>class	BiNode
{
public:
	T	val;
	BiNode<T>	*lch;
	BiNode<T>	*rch;
	BiNode(T	v) :val(v), lch(NULL), rch(NULL) {};	//���캯�� 
	BiNode():lch(NULL), rch(NULL) {};	//���캯��
	//BinaryTreeNode(keyType v):value(v),m_pLeft(nullptr),m_pRight(nullptr){}

};

template<class	T>class	BST
{

public:
	BST(T	r[], int	n);	//���캯��   
	//~BST();	//�������� 
	bool Search(BiNode<T>*R,T	key);	//���ҹؼ���key
	BiNode<T> *insertBiNode(BiNode<T> *&root, T val);	//������
	void	Delete(BiNode<T>*&R);	//ɾ�����
	bool	DeleteBST(BiNode<T>*&R,T	key);	//ɾ���ؼ���key 
	int 	height(BiNode<T>* root); 	//�ж����ĸ߶� 	 
	bool 	isBalanced(BiNode<T>* root); //�ж����Ƿ�Ϊ����ƽ���� 
	int		diff(BiNode<T>	*root);	//����ƽ������ 
	BiNode<T>	*balance(BiNode<T>	*root);	//ƽ����� 
	void    inorder(BiNode<T>*	root, vector<int>&res);
	vector<int> inorderTraversal(BiNode<T>* root);	//����������� 
	vector<vector<T>>	levelOrder(BiNode<T>* root);	//����������� 


	//��ת������ 
	BiNode<T> *LL_Rotation(BiNode<T> *root);
	BiNode<T> *LR_Rotation(BiNode<T> *root);
	BiNode<T> *RL_Rotation(BiNode<T> *root);
	BiNode<T> *RR_Rotation(BiNode<T> *root);


	BiNode<T>*root; 	//���ڵ� 
};

//����ƽ������
template<class	T>
int BST<T>::diff(BiNode<T> *root)
{
	if (root == NULL)
		return 0;
	return height(root->lch) - height(root->rch);
}


//�ĸ���ת����

template <class	T>
BiNode<T> *BST<T>::LL_Rotation(BiNode<T> *root)
{
	BiNode<T> *temp = root->lch;
	root->lch = temp->rch;
	temp->rch = root;
	return temp;//����Ҫ��ת����������� 
}


template <class	T>
BiNode<T> *BST<T>::RR_Rotation(BiNode<T> *root)
{
	BiNode<T> *temp = root->rch;
	root->rch = temp->lch;
	temp->lch = root;
	return temp;
}

template <class	T>
BiNode<T> *BST<T>::LR_Rotation(BiNode<T> *root)
{//�Ƚ���RR�������ٽ���LL���� 

	//ע������һ��Ҫ��root->m_Pleft���¸�ֵ 
	root->lch = RR_Rotation(root->lch);//�ȶ�root����������RR���� 
	return LL_Rotation(root);//�ٶ�root����LL���� 
}

template <class	T>
BiNode<T> *BST<T>::RL_Rotation(BiNode<T> *root)
{//�Ƚ���LL�������ٽ���RR���� 

	//ע������һ��Ҫ��root->m_pRight���¸�ֵ 
	root->rch = LL_Rotation(root->rch);//�ȶ�root����ҽ�����LL���� 
	return RR_Rotation(root);//�ٶ�root����RR���� 
}


//ƽ����� 
template <class	T>
BiNode<T> *BST<T>::balance(BiNode<T> *root)
{
	int dis = diff(root);//�������ƽ������ 
	if (dis > 1) {//�� 
		if (diff(root->lch) > 0)
			return LL_Rotation(root);
		else
			return LR_Rotation(root);
	}
	else if (dis < -1) {//�� 
		if (diff(root->rch) < 0)
			return RR_Rotation(root);
		else
			return RL_Rotation(root);
	}

	return root;//����ת��ʱ�ǵ÷���root 
}


//������ 
template <class	T>
BiNode<T> * BST<T>::insertBiNode(BiNode<T> *&root, T val)	//���ĸ��ڵ��Ҫ�����ֵ 
{
	if (root == NULL)
	{
		root = new BiNode<T>(val);
		return root;
	}
	if (val == root->val)
	{
		return root;
	}
	else if (val < root->val)
	{
		//root->lch = insertBiNode(root->lch,val);
		insertBiNode(root->lch, val);
		root = balance(root); //ע�������ǰ�ƽ���ķ�����temp��ֵ��root 
		return root;
	}
	else {
		//root->rch = insertBiNode(root->rch,val);
		insertBiNode(root->rch, val);
		root = balance(root);
		return root;
	}
}


//���캯��
template<class	T>
BST<T>::BST(T	r[], int	n)	//���캯�� 
{
	root = NULL;
	for (int i = 0; i < n; i++)
		insertBiNode(root, r[i]);
}









template<class	T>
int BST<T>::height(BiNode<T>* root) 	//�ж����ĸ߶� 
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return max(height(root->lch), height(root->rch)) + 1;
	}
}
template<class	T>
bool	BST<T>::isBalanced(BiNode<T>* root) //�ж����Ƿ�Ϊ����ƽ���� 
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
}



//�������
template<class	T>
void	BST<T>::inorder(BiNode<T>*	root, vector<int>&res)
{
	if (!root)
		return;
	inorder(root->lch, res);
	res.push_back(root->val);
	inorder(root->rch, res);
}

template<class	T>
vector<int>	BST<T>::inorderTraversal(BiNode<T>* root)
{
	vector<T>res;
	inorder(root, res);
	return	res;
}


//�������
template<class	T>
vector<vector<T>>	BST<T>::levelOrder(BiNode<T>* root)
{
	vector <vector <T>> ret;
	if (!root)
	{
		return ret;
	}

	queue<BiNode<T>*>q;
	q.push(root);
	while (!q.empty())
	{
		int currentLevelSize = q.size();
		ret.push_back(vector <T>());
		for (int i = 1; i <= currentLevelSize; ++i)
		{
			auto node = q.front(); q.pop();
			ret.back().push_back(node->val);
			if (node->lch) q.push(node->lch);
			if (node->rch) q.push(node->rch);
		}
	}

	return ret;
}

//���Һ���
template<class T>
bool	BST<T>::Search(BiNode<T>*R, T	key)
{
	if (R == NULL)
		return	false;
	if (key == R->val)
		return	true;
	else if (key < R->val)
		return Search(R->lch, key);
	else
		return Search(R->rch, key);
}


//ɾ������
template<class	T>
bool	BST<T>::DeleteBST(BiNode<T>*&R,T key)
{
	if(R==NULL)
		return	false;
	else	
	{
		if(key==R->val)
		{
			Delete(R);
			return	true;
		}
		else	if(key<R->val)
			return	DeleteBST(R->lch,key);
		else	
			return	DeleteBST(R->rch,key);
	}
}

template<class	T>
void	BST<T>Delete(BiNode<T>*&R)
{
	BiNode<T>*q,*s;
	if(R->lch==NULL)
	{
		q=R;
		R=R->rch;
		delete	q;
	}
	else	if(R->rch==NULL)
	{
		q=R;
		R=R->lch;
		delete	q;
	}
	else
	{
		q=R;
		s=R->lch;
		while(s->rch!=NULL)
		{
			q=s;
			s=s->rch;
		}
		R->val=s->val;
		if(q!=R)
			q->rch=s->lch;
		else
			R->lch=s->lch;
		delete	s; 
	}
}






