#include<bits/stdc++.h>
using namespace  std;
int dp[100][100];
int main()
{
		
	char a[1001],b[1001];
	while(scanf("%s",a)&&a[0]!='#')
	{
		scanf("%s",b);
		int len1,len2;
		len1=strlen(a);
		len2=strlen(b);
		int flag=0,num=0;
		for(int i=0;i<len1;i=i+len2)
		{
				for(int j=0;j<len2;j++)
				{
					if(a[i+j]!=b[j])
						flag=1;
				}
				if(flag==0)num++;
				flag=0;
		}
		printf("%d\n",num);
    }
   return 0;

} 