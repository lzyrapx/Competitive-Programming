#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int res=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return res;
}
int main()
{
	int n,p;
	int x,y;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		
		exgcd(i,p,x,y);
		printf("%d\n",(x+p)%p);
	}
	return 0;
}