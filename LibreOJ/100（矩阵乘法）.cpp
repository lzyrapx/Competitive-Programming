#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
const ll mod = 1e9 + 7;
const int N =1e6+6; 
const int M=100010;
const int maxn=1234;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("runtime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
ll A[maxn][maxn],B[maxn][maxn],C[maxn][maxn];
int n,m,p;
void matrix_mul()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            C[i][j] = 0;
            for(int k = 0; k < p; k++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j] )%mod;
            }
            if(C[i][j] < 0) C[i][j] = (C[i][j] + mod)%mod;
        }
    }
}
int main()
{
	
    //timer t;
    cin>>n>>p>>m;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
        {
        	cin>>A[i][j];
		}
            
    for(int i = 0; i < p; i++)
        for(int j = 0; j < m; j++)
        {
        	cin>>B[i][j];
		}
            
    matrix_mul();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<C[i][j];
            if(j == m-1) cout<<endl;
            else cout<<" ";
        }
    }
    
	return 0;
}