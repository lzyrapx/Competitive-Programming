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
	int a[101],i,num,num1,rank,mark1,mark;
	while(cin>>num)
	{
		memset(a,0,sizeof(a));
		while(cin>>num1>>mark1&&(num1!=0||mark1!=0))
		{
			if(num1==num)
				mark=mark1;
			a[mark1]++;
		}
		for(i=100,rank=1;i>mark;i--)
			rank+=a[i];
		cout<<rank<<endl;
	}	
    return 0;

}