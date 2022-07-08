#include<bits/stdc++.h>
#include"Huffman.h" 
using	namespace	std;
int	main()
{
	Huffman	Huf;
	int	a[5]={1,2,3,4,5};
	char	name[5]={'A','B','C','D','E'};
	Huf.CreateHTree(a,5,name);
}
