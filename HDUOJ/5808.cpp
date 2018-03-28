//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 20000+10;
const int mod=998244353;
const int M=1e5+10;
const int INF= 1e9;
struct A
{
	int v,d,ord;
}a[N];

struct Q
{
	int l,r,d,sum,ord;
}q[M];

int n,m,C[N][110],ans[M];

int cmp(A a, A b)
{
	return a.d < b.d;
}

int cmp2(Q a, Q b)
{
	return a.d < b.d;
}

int lowbit(int x)
{
	return x & (-x);
}

void add(int x, int y)
{
	for(int i = x ;i <= n; i += lowbit(i)){
		C[i][y]++;
	}
}

int query(int x,int y)
{
	int ans = 0;
	for(int i = x; i >= 1; i -= lowbit(i)){
		ans+=C[i][y];
	}
	return ans;
}

bool e[110];
int b[3010];
int f[110];
int main()
{
	//freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i].v);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].d), a[i].ord=i;
		}
		sort(a+1,a+n+1,cmp);
		memset(C,0,sizeof(C));
		for(int i=1; i <= m; i++){
			scanf("%d%d%d%d",&q[i].l, &q[i].r, &q[i].d, &q[i].sum);
			q[i].ord = i;
			
		}
		sort( q+1 , q+m+1 , cmp2);
		a[n+1].d = INF+10;
		int l = 1;
		for(int i=1; i<=m; i++)
		{
			while(a[l].d <= q[i].d && l <= n)
			{
				add(a[l].ord,a[l].v);
				l++;
			}
			int Ans = query(q[i].r, q[i].sum)- query(q[i].l-1 , q[i].sum);
			if(Ans) ans[q[i].ord] = 0;
			//一定买不了 
			else{
				int cnt = 0;
				for(int j = 1; j < q[i].sum; j++){
					int y = query(q[i].r , j) - query(q[i].l - 1, j);
					int p = 1;
					while(p < y){
						b[++cnt] = j * p;
						y -= p;
						p <<= 1;
					}
					if(y) b[++cnt] = y*j;
				}
				memset(f,0,sizeof(f));
				f[0] = 1;
				for(int j = 1; j <= cnt; j++){
					for(int v = q[i].sum; v >= b[j]; --v){
						f[v]= max(f[v],f[v-b[j]]);
					}
				}
				if(f[q[i].sum]) ans[q[i].ord] = 0;
				else ans[q[i].ord] = 1;
			}
		}
		for(int i=1; i<=m ; i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
