#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;  
	int cas=1; 
	char str[500];
	int ans,dep;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		ans=0;
		dep=0;
		for(int i=0;str[i];i++)
		{
			if(str[i]=='[')
				dep++;
			else 
				dep--;
			if(dep>ans)
				ans=dep;
		}
		int res=1;
		for(int i=0;i<ans;i++)
		{
			res*=2;
		}
		printf("%d %d\n",cas++,res);
		
	}

	return 0;
}