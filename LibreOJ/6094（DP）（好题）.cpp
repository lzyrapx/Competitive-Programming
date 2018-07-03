#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500;
const int MOD=1000000007;
void add_mod(int &a,ll b) { a=(a+b)%MOD; }

int n;
int d[MAXN];
// Let ways[c0][c1][c2] be the number of ways to build a single level with c0 vertices (their "plugs" don't matter), 
//and connect it to the previous layer which has c1 "1-plug" vertices and c2 "2-plug" ones. 
//Recursion over ways[] can be done in O(1).
int ways[MAXN+1][MAXN+1][MAXN+1]; 

int sum2[MAXN+1];
int sum3[MAXN+1];
// let mem[l][r] be the number of ways to build the graph with vertices from l to n, 
//while vertices from l to r form the first level — 
//note that this level should be connected to another previous one
int mem[MAXN][MAXN+1]; 

int go(int a,int b)
{
	int &ret=mem[a][b]; 
	if(ret==-1)
	{
		ret=0;
		int n1=sum2[b]-sum2[a];
		int n2=sum3[b]-sum3[a];
		if(b==n)
		{
			add_mod(ret,ways[n1][n2][0]);
		} 
		else
		{
			for(int c = b + 1; c <= n; c++)
			{
				int x = c - b;
				add_mod(ret,1LL*ways[n1][n2][x] * go(b,c));
			}
		}
//		printf("go(%d,%d)=%d [n1=%d,n2=%d]\n",a,b,ret,n1,n2);
	}
	return ret;
}

int solve()
{
	if(n==3&&d[0]==3) return 0;
	memset(ways,0,sizeof(ways));
	for(int sumprev = 0; sumprev <= n ; sumprev++)
	{
		
		for(int b = 0; b <= sumprev / 2; b++)
		{
			int a = sumprev - 2 * b;
			for(int c = 0; c <= n ; c++)
			{
				if(c>0)
				{
					if(a>=1) add_mod(ways[a][b][c],1LL * a * ways[a-1][b][c-1]);
					if(b>=1) add_mod(ways[a][b][c],1LL * b * ways[a+1][b-1][c-1]);
				} 
				else if(a>0)
				{
					if(a>=2) add_mod(ways[a][b][c],1LL * (a-1) * ways[a-2][b][c]);
					if(b>=1) add_mod(ways[a][b][c],1LL * b * ways[a][b-1][c]);
				} 
				else if(b>0)
				{
					if(b>=3) add_mod(ways[a][b][c],1LL * (b-1) * (b-2) / 2 % MOD * ways[a+2][b-3][c]);
				} 
				else
				{
					ways[a][b][c] = 1;
				}
			}
		}
	}
//	for(int a = 0;a <= n ; a++)
//	 	for(int b = 0;b <= n ; b++) 
//	 		for(int c = 0;c <= n ; c++) 
	//		 	if(ways[a][b][c]>0) printf("(%d,%d,%d)=%d\n",a,b,c,ways[a][b][c]);

	sum2[0]=0; 
	for(int i = 0; i < n; i++) sum2[i+1] = sum2[i] + (d[i] == 2 ? 1 : 0);
	
	sum3[0]=0; 
	for(int i = 0 ; i < n; i++) sum3[i+1] = sum3[i] + (d[i] == 3 ? 1 : 0);
	
//	for(int i = 0;i <= n ; i++) printf("%d: %d %d\n",i,sum2[i],sum3[i]);
	memset(mem,-1,sizeof(mem));
	return go(1,1+d[0]);
}

int main()
{
	scanf("%d",&n); 
	for(int i=0;i<n;i++) scanf("%d",&d[i]);
	printf("%d\n",solve());
	return 0;
}