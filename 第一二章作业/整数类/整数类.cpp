#include<bits/stdc++.h>
using	namespace	std;
int	pri[21]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
class	integer{
	private:
		int	n1;
		int	n2;//求上两个数的最大公约数或最小公倍数 
		int	n3;//求次数的因式分解 
	public:
		void	set(int	x1,int	x2);
		void	set1(int	x1);
		void	lcm();//求最小公倍数的函数
		void	gcd();//求最大公约数的函数
		void	fac();//求因式分解的函数  
};

void	integer::set(int	x1,int	x2)
{
	n1=x1;	n2=x2;	
}
void	integer::set1(int	x1)
{
	n3=x1;
}

void	integer::gcd()
{
	long	int	x=n1*n2;
	long	int	y=n1%n2;
	while(y)
	{
		n1=n2;
		n2=y; 
		y=n1%n2;
	}
	cout<<"最大公约数为"<<n2<<endl; 
}

void	integer::lcm()
{
	long	int	x=n1*n2;
	long	int	y=n1%n2;
	int		m;
	while(y)
	{
		n1=n2;
		n2=y;
		y=n1%n2;
	}
	m=x/n2;
	cout<<"最小公倍数为"<<m<<endl; 	
}

void	integer::fac()
{
	int n,i;
    n=n3;
    for(i=2;i<=n;i++)
  	{
	  	while(n%i==0)
        {
       	    printf("%d",i);
            n/=i;
            if(n!=1) printf("*");
        }
    }
    printf("\n");    
}

int	main()
{
	integer	myinteger;
	int	s1,s2;
	cout<<"求最大公约数输入1，最小公倍数输入2，分解因数输入3"<<endl;
	int	n;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<"请输入要求的两数"<<endl;
			cin>>s1>>s2;
			myinteger.set(s1,s2);
			myinteger.gcd();
		}
		else	if(n==2)
		{
			cout<<"请输入要求的两数"<<endl;
			cin>>s1>>s2;
			myinteger.set(s1,s2);
			myinteger.lcm();
		}
		else	if(n==3)
		{
			cout<<"请输入要求的数"<<endl;
			cin>>s1; 
			myinteger.set1(s1);
			myinteger.fac();
		}
		cout<<"求最大公约数输入1，最小公倍数输入2，分解因数输入3"<<endl;
	}
} 




