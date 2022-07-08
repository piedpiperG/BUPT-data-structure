#include<iostream>
#include"ALGraph.h" 
using	namespace	std;
int	main()
{
	ALGraph<char>ALG;
	ALG.print();
	ALG.DFS(1);
}
//6 1
//1 2
//2 5
//1 3
//3 2
//3 4
