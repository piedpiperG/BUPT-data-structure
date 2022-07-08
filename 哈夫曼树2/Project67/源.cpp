#include<iostream>
#include<cstring>
#include<string>
#include"Huffman.h"
using	namespace	std;
#define Size	100
string	str;
char	name[60];//�ַ����ͣ�0-25Ϊ��д��30-55ΪСд,26Ϊ�»��ߣ� 
int		Time[60];//�ַ���Ȩֵ 
char	name2[60];
int		Time2[60];
int	main()
{
	cout << "���������봫�ݵ��ַ���(�ո����»��ߴ���),�����������������(END)" << endl;
	while (cin >> str)
	{
		if (str == "END")
			break;
		memset(Time, 0, sizeof(Time));
		memset(Time2, 0, sizeof(Time2));
		int	len = str.size();
		if (len > Size)
		{
			cout << "�����������ɴ���Χ" << endl;
			cout << "���������봫�ݵ��ַ���(�ո����»��ߴ���),�����������������(END)" << endl;
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
		}//¼�벢�����ַ��� 
		int	retime = 0;//ʵ���ϳ��ֵ��ַ����� 
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
		//��ϸ����������
		//��������ɹ��� 
		Huffman	Huf;
		//cout << retime << endl;
		Huf.CreateHTree(Time2, retime, name2);
		Huf.CreateCodeTable();			//���ͱ�Ľ��� 
		Huf.Printeach(retime);//��ӡÿһ���ַ���Ӧ�Ĺ��������� 
		char	*ar = new	char[Size];//�������ַ���
		char	*br = new	char[Size];//�������ַ���
		int	contro=0;
		Huf.Encode(str, ar,contro);
		cout << "����������:" << endl;
		for (int i = 0; i < contro; i++)
			cout << *(ar + i);
		cout << endl;
		//cout << ar << endl;
		cout << "����������:" << endl;
		Huf.Decode(ar, br);
		for (int i = 0; i < len; i++)
			cout << *(br + i) ;
		cout << endl;
		cout << "����������Ҫ�ĳ����ǣ�" << len*5 << ";" << "����������ĳ�����:" << contro << endl;
		cout << "ԭ�������±����" << len * 5 * 1.0 / contro <<"��"<< endl;
		Huf.~Huffman();
		cout << endl;
		cout << "���������봫�ݵ��ַ���(�ո����»��ߴ���),�����������������(END)" << endl;
	}
}