#include<bits/stdc++.h>
using namespace std;

int a[25];
int n;
int averlen;
int flag;
bool vis[25];
void dfs(int num,int len,int start)//成功边数,目前长度,开始位置
{
	if(flag) return;
	if(num==4){
		flag = 1;return;
	}
	if(len==averlen)
	{
		dfs(num+1,0,0);
		if(flag)return;
	}
	for(int i=start;i<n;i++)
	{
		if(!vis[i] && len + a[i] <= averlen)
		{
			vis[i] = 1;
			dfs(num,len+a[i],i+1);
			vis[i] = 0;
			if(flag) return;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0,maxlen=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]>maxlen) maxlen = a[i];
		}
		averlen = sum / 4;
		if(sum%4!=0 | maxlen > averlen)
		{
			cout<<"no"<<endl;continue;
		}
		sort(a,a+n);
		memset(vis,0,sizeof vis);
		flag = 0;
		dfs(0,0,0);
		if(flag) puts("yes");
		else puts("no");
	}
	return 0;
} 