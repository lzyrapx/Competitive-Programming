#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[64];
/*
如果能在指定步数内直接移动第n个盘子，那么就相当于，
可以把1柱子上n-1个盘移动到2柱子上，第n个盘子移动到3柱子上；
如果不能说明第n个盘仍然只能留在1柱子上，
继续试探第n-1个盘能否直接移动到柱子3上....依次类推
*/
void hanoi(ll n,ll m,ll x[],ll y[], ll z[])
{
	if(m>a[n-1])
	{
		z[z[0]++]=n;
		hanoi(n-1,m-a[n-1],y,x,z);
	}
	else if(m==a[n-1])//1柱子上n-1个盘移动到2柱子上
	{
		z[z[0]++]=n;
		for(int i=1;i<n;i++)y[y[0]++]=n-i;
	}
	else 
	{
		x[x[0]++]=n;
		hanoi(n-1,m,x,z,y);
	}
}
ll x[64],y[64],z[64];
int main()
{
	ll n,m;
	int t ;
	a[0]=1;
	for(int i=1;i<=63;i++) a[i]=a[i-1]*2;
	cin>>t;
	while(t--)
	{
		x[0]=y[0]=z[0]=1;
		cin>>n>>m;
		hanoi(n,m,x,y,z);
		
		cout<<x[0]-1;
		for(int i=1;i<x[0];i++)printf(" %lld",x[i]);
		cout<<endl;
		
		cout<<y[0]-1;
		for(int i=1;i<y[0];i++)printf(" %lld",y[i]);
		cout<<endl;
		
		cout<<z[0]-1;
		for(int i=1;i<z[0];i++)printf(" %lld",z[i]);
		cout<<endl;
	
	}
	return 0;
}