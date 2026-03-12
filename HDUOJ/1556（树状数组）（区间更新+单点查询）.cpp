#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
int n;
int c[123456];
int lowbit(int x){
	return x&(-x);
}
void update(int x,int val)//向前修改
{
    while(x)
    {
   		c[x]+=val;
   		x-=lowbit(x);
	}
} 
int sum(int x)//求和即为修改的次数 
{
	int res = 0;
	while(x<=n)
	{
		res+=c[x];
		x+=lowbit(x);
	}
	return res;
}
int main()
{
	int x,y;
	while(cin>>n)
	{
		if(n==0)break;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			update(y,1);//从右区间向前修改
			update(x-1,-1); //从左区间向前修改，恢复那些不需要修改的值 
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",sum(i));//sum(i)就是修改的次数	
		}
		puts(""); 
	} 
	return 0;
} 