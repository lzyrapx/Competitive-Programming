#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const int mod = 1000000007;
const int N = 2010; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
typedef int Matrix[N][N];
int prime[N], vis[N];
Matrix A;
int init(int m)
{
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 2; i < m; i++){
        if (!vis[i]) {
            prime[ans++] = i;
            for (int j = i * i; j < m; j += i)
                vis[j] = 1;
        }
    }
    return ans;
}
int gauss(Matrix A, int m, int n) {
    int i = 0, j = 0 ;
	int k, r, u;
    while (i < m && j < n)
	{
        r = i;
        for (k = i; k < m; k++)
        {
        	if (A[k][j])
			{
                r = k;
                break;
            }   
		}
        if (A[r][j])
		{
            if (r != i)
            {
               	for (k = 0; k <= n; k++)
                {
                 	swap(A[r][k], A[i][k]);
				}      	
			} 
            for (u = i+1; u < m; u++)
            {
               	if (A[u][j])
                {
                   	for (k = i; k <= n; k++)
                    {
                        A[u][k] ^= A[i][k];
					}
				} 	
			} 
            i++;
        }
        j++;
    }
    return i;
}
ll q_mod(ll a,ll b,ll m)
{
    ll ans = 1;
    while(b)
	{
        if(b&1)   	
            ans = (ans * a) % m;
          b>>=1;
        a = a * a % m;
    }
    return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int m = init(2010);
    int t;
    int cas= 1;
    t=read();
    while (t--)
	{
        int n;
		int maxx= 0;
        ll x;
        n=read();
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; i++)
		{
            scanf("%lld", &x);
            for (int j = 0; j < m; j++)
                while (x % prime[j] == 0)
				{
                    maxx = max(maxx, j);
                    x /= prime[j];
                    A[j][i] ^= 1;
                }
        }
        int r = gauss(A, maxx+1, n);
        int ans = q_mod(2, (ll)(n-r), mod);
        printf("Case #%d:\n%d\n", cas++ , ans-1);
    }
	return 0;
}
