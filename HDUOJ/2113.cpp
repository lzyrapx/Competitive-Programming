#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	int i,max;	int flag=0;
	char a[100];
	while(gets(a))
	{
		max=0;
	     for(i=0;a[i]!='\0';i++)
    	{
		if((a[i]-'0')%2==0)
		max=max+(a[i]-'0');		
	    }

	if(flag!=0)
	printf("\n");  //注意输出格式
	printf("%d\n",max);
	flag=1;
	}
	return 0;
}