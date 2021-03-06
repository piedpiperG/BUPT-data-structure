#include<iostream>
#include<cstring>
#include<string>
#include"Huffman.h"
using	namespace	std;
#define Size	100
string	str;
char	name[60];//字符类型（0-25为大写，30-55为小写,26为下划线） 
int		Time[60];//字符的权值 
char	name2[60];
int		Time2[60];
int	main()
{
	cout << "请输入你想传递的字符串(空格用下划线代替),如想结束程序，请输入(END)" << endl;
	while (cin >> str)
	{
		if (str == "END")
			break;
		memset(Time, 0, sizeof(Time));
		memset(Time2, 0, sizeof(Time2));
		int	len = str.size();
		if (len > Size)
		{
			cout << "数据量超过可处理范围" << endl;
			cout << "请输入你想传递的字符串(空格用下划线代替),如想结束程序，请输入(END)" << endl;
			continue;
		}
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '_')
			{
				Time[26]++;
				name[26] = '_';
			}
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				Time[str[i] - 'A']++;
				name[str[i] - 'A'] = str[i];
			}
			if (str[i] >= 'a'&&str[i] <= 'z')
			{

				Time[str[i] - 'a' + 30]++;
				name[str[i] - 'a' + 30] = str[i];

			}
		}//录入并处理字符串 
		int	retime = 0;//实际上出现的字符个数 
		for (int i = 0; i < 60; i++)
		{
			if (Time[i] != 0)
			{
				name2[retime] = name[i];
				Time2[retime] = Time[i];
				retime++;
			}
		}
		//cout << "retime=" << retime << endl;
		name2[retime] = '\0';
		//精细化两个数组
		//运用类完成功能 
		Huffman	Huf;
		//cout << retime << endl;
		Huf.CreateHTree(Time2, retime, name2);
		Huf.CreateCodeTable();			//树和表的建立 
		Huf.Printeach(retime);//打印每一个字符对应的哈夫曼编码 
		char	*ar = new	char[Size];//编码后的字符串
		char	*br = new	char[Size];//解码后的字符串
		int	contro=0;
		Huf.Encode(str, ar,contro);
		cout << "编码结果如下:" << endl;
		for (int i = 0; i < contro; i++)
			cout << *(ar + i);
		cout << endl;
		//cout << ar << endl;
		cout << "解码结果如下:" << endl;
		Huf.Decode(ar, br);
		for (int i = 0; i < len; i++)
			cout << *(br + i) ;
		cout << endl;
		cout << "定长编码需要的长度是：" << len*5 << ";" << "哈夫曼编码的长度是:" << contro << endl;
		cout << "原编码是新编码的" << len * 5 * 1.0 / contro <<"倍"<< endl;
		Huf.~Huffman();
		cout << endl;
		cout << "请输入你想传递的字符串(空格用下划线代替),如想结束程序，请输入(END)" << endl;
	}
}