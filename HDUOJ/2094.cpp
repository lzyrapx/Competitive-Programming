#include<bits/stdc++.h>
using namespace  std;

int main()
{
	int n;
	int in[1200],ans;
	string a,b;
	map<string,int> mp;
	while(~scanf("%d",&n)&&n)
	{
		int y=1;
		memset(in,0,sizeof(in));
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(mp[a]==0)mp[a]=y++;
			cin>>b;
			if(mp[b]==0)mp[b]=y++;
			in[mp[b]]++;
		}
		ans=0;
		for(int i=1;i<y;i++){
			if(in[i]==0)ans++;
		}
		if(ans==1)puts("Yes");
		else puts("No");
	}
 } 