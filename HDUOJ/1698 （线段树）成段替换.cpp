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
const int maxn=100010;
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
int sum[maxn<<2];
int col[maxn<<2];
int n,m;
void pushup(int rt) //把当前结点的信息更新到父结点
{
	//线段树是用数组来模拟树形结构
	//对于每一个节点rt,左子节点为 2*rt (一般写作rt<<1)右子节点为 2*rt+1（一般写作rt<<1|1） 
	sum[rt] = sum[rt<<1] + sum[rt<<1|1]; 
}
void pushdown(int rt , int m)//把当前结点的信息更新到子节点 
{
	if(col[rt]){
		col[rt<<1] = col [rt<<1|1]=col[rt];
		sum[rt<<1] = (m - (m>>1)) * col[rt];
		sum[rt<<1|1] = (m>>1) * col[rt];
		col[rt] = 0;
	}
}
void build(int l,int r,int rt)
{
	col[rt] = 0;
	sum[rt] = 1;
	if(l==r)
	{
		 return;
	}
	int mid=(l+r)>>1;
	build(lson);//递归构造左子树
	build(rson);//递归构造右子树
	pushup(rt); //更新
}

void update(int L,int R,int c, int l,int r,int rt) //成段替换
{
	if(L <= l && r <= R){
		col[rt] = c;
		sum[rt] = c*(r - l + 1);
		return ;
	}
	pushdown(rt, r - l + 1);
	int mid = (l+r)>>1;
	int ans = 0;
	if(L <= mid) update(L, R, c, lson);
	if(R > mid) update(L, R, c, rson);
	pushup(rt);
}
int main()
{
	int t; 
	int cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		build(1,n,1);
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas++,sum[1]); 
	 }
    	return 0;
}