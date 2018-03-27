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
	int T;
	cin>>T;
	getchar();
	while(T--)
	{	
		int flag=1;
		int i=1;
		char a[52]={0};
		gets(a);
		if (a[0]=='_'||(a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z')) //开头字母 
		flag=1;
		else
			flag=0;
		for (i=1;i<strlen(a)&&flag;i++) //其他字母 
		{
			if (a[i]=='_'||(a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9'))
				continue;
			else
			{
				flag=0;;
				break;
			}
		}
		printf (flag?"yes\n":"no\n");
    }
	return 0;
}