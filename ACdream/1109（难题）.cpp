/*
* this code is made by LzyRapx
* Problem: 1109
* Verdict: Accepted
* Submission Date: 2017-07-28 22:47:52
* Time: 1992MS
* Memory: 1748KB
*/
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define M 105
#define N 60
#define mod 19921214
 
map< vector<int>, int > mp;
map< vector<int>, int >::iterator it;
 
int t;
int m, K;
int in[14];
int g[60][60];
int a[N][N], b[N][N], c[N][N];
int fac[20];
void dfs( int d, int lft )
{
    if( d >= K )
    {
        if( lft ) return;
        vector<int> vec;
        for( int i = 0; i < K; i++ ) vec.push_back( in[i] );
        mp[ vec ] = ++t;
        return;
    }
    int s = 0;
    if( d ) s = in[d-1];
    for( int i = s; i <= lft && i <= m; i++ )
    {
        in[d] = i;
        dfs( d + 1, lft - i );
    }
}
int gao( vector<int> &vec )
{
    int s = fac[K];
    int i = 0, j;
    while( i < K )
    {
        j = i;
        while( j < K && vec[i] == vec[j] ) ++j;
        s /= fac[j-i];
        i = j;
    }
    return s;
}
  
void init()
{
    mp.clear();
    t = 0;
    dfs( 0, K );
    vector<int> v1, v2;
    int u, v;
    int s;
    memset( g, 0, sizeof(g) );
    for( it = mp.begin(); it != mp.end(); it++ )
    {
        u = it->second;
        v1 = it->first; 
        s = gao( v1 );
        for( int i = 0; i < K; i++ )
        {
            for( int j = 0; j < K; j++ )
            {
                v2 = v1;
                if( v2[j] == 0 ) continue;
                v2[i]++;
                v2[j]--;
                if( v2[i] > m ) continue;
                sort( v2.begin(), v2.end() );
                v = mp[ v2 ];
                g[u][v] = ( 1 + g[u][v] ) % mod;
            }
        } 
             
    }
}
  
void mul( int a[][N], int b[][N], int n )
{
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ ) c[i][j] = 0;
    }
         
    for( int k = 1; k <= n; k++ )
    {
        for( int i = 1; i <= n; i++ ) 
        {
            if( a[i][k] )
            {
                for( int j = 1; j <= n; j++ )
                {
                    if( b[k][j] )
                    {
                        c[i][j] = ( c[i][j] + 1LL * a[i][k] * b[k][j] ) % mod;
                    }
                 
                }
            }
        }
    }
                    
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            a[i][j] = c[i][j];
        }
    }
         
}
  
void fMod( int a[][N], int m, ll n )
{
    for( int i = 1; i <= m; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            b[i][j] = i == j;
        }
    }    
    while( n )
    {
        if( n & 1 ) mul( b, a, m );
        mul( a, a, m );
        n >>= 1;
    }
}
  
int main()
{
    ll n;
    vector<int> vec;
    fac[0] = 1;
    for( int i = 1; i <= 13; i++ ) fac[i] = fac[i-1] * i;
    int T;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf("%lld%d%d", &n, &K, &m );
        init(); 
        vec.clear();
        for( int i = 0; i < K; i++)
        {
            scanf( "%d", in + i );
            vec.push_back( in[i] );
        }
        sort( vec.begin(), vec.end() );
        fMod( g, t, n );
        int ans = 0;
        int u = mp[ vec ];
        for( int i = 1; i <= t; i++ )
        {
            ans = ( ans + b[u][i] ) % mod;
        }
             
        printf( "%d\n", ans );
    }
    return 0;
}