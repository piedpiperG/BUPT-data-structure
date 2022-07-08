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
	BiNode(T	v) :val(v), lch(NULL), rch(NULL) {};	//构造函数 
	BiNode():lch(NULL), rch(NULL) {};	//构造函数
	//BinaryTreeNode(keyType v):value(v),m_pLeft(nullptr),m_pRight(nullptr){}

};

template<class	T>class	BST
{

public:
	BST(T	r[], int	n);	//构造函数   
	//~BST();	//析构函数 
	bool Search(BiNode<T>*R,T	key);	//查找关键字key
	BiNode<T> *insertBiNode(BiNode<T> *&root, T val);	//插入结点
	void	Delete(BiNode<T>*&R);	//删除结点
	bool	DeleteBST(BiNode<T>*&R,T	key);	//删除关键字key 
	int 	height(BiNode<T>* root); 	//判断树的高度 	 
	bool 	isBalanced(BiNode<T>* root); //判断树是否为二叉平衡树 
	int		diff(BiNode<T>	*root);	//计算平衡因子 
	BiNode<T>	*balance(BiNode<T>	*root);	//平衡操作 
	void    inorder(BiNode<T>*	root, vector<int>&res);
	vector<int> inorderTraversal(BiNode<T>* root);	//中序遍历函数 
	vector<vector<T>>	levelOrder(BiNode<T>* root);	//层序遍历函数 


	//旋转函数集 
	BiNode<T> *LL_Rotation(BiNode<T> *root);
	BiNode<T> *LR_Rotation(BiNode<T> *root);
	BiNode<T> *RL_Rotation(BiNode<T> *root);
	BiNode<T> *RR_Rotation(BiNode<T> *root);


	BiNode<T>*root; 	//根节点 
};

//计算平衡因子
template<class	T>
int BST<T>::diff(BiNode<T> *root)
{
	if (root == NULL)
		return 0;
	return height(root->lch) - height(root->rch);
}


//四个旋转操作

template <class	T>
BiNode<T> *BST<T>::LL_Rotation(BiNode<T> *root)
{
	BiNode<T> *temp = root->lch;
	root->lch = temp->rch;
	temp->rch = root;
	return temp;//返回要旋转子树的主结点 
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
{//先进行RR操作，再进行LL操作 

	//注意这里一定要对root->m_Pleft重新赋值 
	root->lch = RR_Rotation(root->lch);//先对root后的左结点进行RR操作 
	return LL_Rotation(root);//再对root进行LL操作 
}

template <class	T>
BiNode<T> *BST<T>::RL_Rotation(BiNode<T> *root)
{//先进行LL操作，再进行RR操作 

	//注意这里一定要对root->m_pRight重新赋值 
	root->rch = LL_Rotation(root->rch);//先对root后的右结点进行LL操作 
	return RR_Rotation(root);//再对root进行RR操作 
}


//平衡操作 
template <class	T>
BiNode<T> *BST<T>::balance(BiNode<T> *root)
{
	int dis = diff(root);//计算结点的平衡因子 
	if (dis > 1) {//左 
		if (diff(root->lch) > 0)
			return LL_Rotation(root);
		else
			return LR_Rotation(root);
	}
	else if (dis < -1) {//右 
		if (diff(root->rch) < 0)
			return RR_Rotation(root);
		else
			return RL_Rotation(root);
	}

	return root;//无需转换时记得返回root 
}


//插入结点 
template <class	T>
BiNode<T> * BST<T>::insertBiNode(BiNode<T> *&root, T val)	//树的根节点和要插入的值 
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
		root = balance(root); //注意这里是把平衡后的返回置temp赋值给root 
		return root;
	}
	else {
		//root->rch = insertBiNode(root->rch,val);
		insertBiNode(root->rch, val);
		root = balance(root);
		return root;
	}
}


//构造函数
template<class	T>
BST<T>::BST(T	r[], int	n)	//构造函数 
{
	root = NULL;
	for (int i = 0; i < n; i++)
		insertBiNode(root, r[i]);
}









template<class	T>
int BST<T>::height(BiNode<T>* root) 	//判断树的高度 
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
bool	BST<T>::isBalanced(BiNode<T>* root) //判断树是否为二叉平衡树 
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



//中序遍历
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


//层序遍历
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

//查找函数
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


//删除函数
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






