#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000010;
const int mod = 1e9+7;
int n,m,x,y;
int pos,ans;
char c,s[2010];
int main()
{
	cin>>n;
	scanf("%s",s+1);
	cin>>m;
	while(m--)
	{
		cin>>x>>c;
		y = 1;
		pos = x;
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			//for(;y<=n;y++)
			while(y<=n)
			{
				if(s[y]!=c)
				{
					if(pos==0)break;
					--pos;
				}
				y++;
			}
			if(s[i]!=c)pos++;
			if(y-i>ans)ans = y-i;
		}
		cout<<ans<<endl;
	 } 
	return 0;
}