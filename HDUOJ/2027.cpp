#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,m,i,j;
	char text[1000];
	scanf("%d",&n);getchar();
	while(n--)
	{
		int num1=0,num2=0,num3=0,num4=0,num5=0;
		gets(text);
		for(i=0;i<strlen(text);i++)
		{
		    if(text[i]=='a')     num1++;
		    else if(text[i]=='e')num2++;
		    else if(text[i]=='i')num3++;
		    else if(text[i]=='o')num4++;
		    else if(text[i]=='u')num5++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num1,num2,num3,num4,num5);
		if(n)
			printf("\n");


	}
	return 0;
}