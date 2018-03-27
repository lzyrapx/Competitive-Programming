#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=5010;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1    
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int a[maxn];
int n,m;
int c[maxn];
void add(int i,int val)
{
	while(i<=n)
	{
		c[i]+=val;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int s = 0;
	while(i>0)
	{
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}
int main()
{
	
	while(~scanf("%d",&n))
	{
		int ans = 0;
		memset(c,0,sizeof(c)); 
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]++;
			ans+=sum(n)-sum(a[i]);
			add(a[i],1);
		}
		int MIN = ans;
		for(int i=1;i<=n;i++)
		{
			ans-=a[i];//减少的逆序数 
			ans+=n-a[i]+1; //增加的逆序数 
			if(ans<MIN) MIN=ans;
		}
		cout<<MIN<<endl;
	}
    return 0;
}