#include <bits/stdc++.h>
using namespace std;
char a[123];
int main()
{
	int t;
	int ans = 1, num = 1, len;
	cin>>t;
	getchar();
	while(t--)
	{
		ans=num=1;
		gets(a);
		len = strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i] == a[i+1]) num++;
			else
			{
				if(num>ans)
				{
					ans=num;
				}
				num=1;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
 } 