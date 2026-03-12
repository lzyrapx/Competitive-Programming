#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int main(){
	int t;
	char s[117];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&s);
		int k=0;
	    int len = strlen(s);
		if(s[0]=='-')
		printf("-");
		int flag=0;
		for(int i=len-1;i>=0;i--) //字符串反向输出
		{
			if(s[i]=='0'&&flag==0)  //尾数为0时标志为0
			k++;
			else if(s[i]=='-')
			continue;
			else
			{
				flag=1;  //中间的的0不标志
				printf("%c",s[i]);
				
			}
		}
		for(int i=0;i<k;i++)
		  printf("0");
		  printf("\n");
	}
  return 0;
}