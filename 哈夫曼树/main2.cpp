#include<iostream>
#include"Huffman.h" 
using	namespace	std;
int	main()   
{
	Huffman	Huf;
	int	a[4] = { 9,6,1,3 };
	char	name[5] = { 'A','B','Z','C' };
	Huf.CreateHTree(a, 4, name); 
	Huf.CreateCodeTable();
	for (int i = 0; i < 4; i++)
	{
		cout <<"i="<<i<<" "<<Huf.HCodeTable[i].data<<" "<< Huf.HCodeTable[i].code << endl;
	}

}
