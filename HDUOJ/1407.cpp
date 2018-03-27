#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main()
{
   int n,a,b,c,m;
	while(scanf("%d",&n)!=EOF)
	{
		m=0;
		for(a=1;a<=100;a++)
		{
			for(b=a;b<=100;b++)
			{
				for(c=b;c<=100;c++)
				{
					if(n==a*a+b*b+c*c)
					{
						printf("%d %d %d\n",a,b,c);
						m=1;
						break;
					}	
				}
				if(m==1) break; //题目要求：输出它的一个最小正整数解 
			}
			if(m==1) break;  //题目要求：输出它的一个最小正整数解 
		}
	}
	
    return 0;
}