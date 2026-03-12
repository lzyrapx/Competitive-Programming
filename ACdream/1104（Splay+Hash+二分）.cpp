/*
* this code is made by LzyRapx
* Problem: 1104
* Verdict: Accepted
* Submission Date: 2017-07-28 18:18:18
* Time: 708MS
* Memory: 8116KB
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 200010;
 
#define ls son[p][0] //左孩子 
#define rs son[p][1] //右孩子 
 
int son[M][2], fa[M], cnt[M];
int val[M], lft[M], rht[M], bit[M];
int root, t;
void up(int p)
{
    rht[p] = bit[cnt[rs]+1] * rht[ls] + bit[cnt[rs]] * val[p] + rht[rs];
    lft[p] = bit[cnt[ls]+1] * lft[rs] + bit[cnt[ls]] * val[p] + lft[ls];
    cnt[p] = cnt[ls] + cnt[rs] + 1;
}
int newNode(int v)
{
    ++t;
    son[t][0] = son[t][1] = 0;
    cnt[t] = 1;
    val[t] = rht[t] = lft[t] = v;
    fa[t] = 0;
    return t;
}
void init()
{
    root = t = 0;
    son[t][0] = son[t][1] = 0;
    val[t] = rht[t] = lft[t] = cnt[t] = fa[t] = 0;
    root = newNode( 0 );
    son[root][1] = newNode( 0 );
    fa[t] = root;
    up( root );
}
inline void Rotate( int x )
{
    int y = fa[x], z = fa[y];
    int r = son[y][1] == x;
    son[y][r] = son[x][!r], fa[son[y][r]] = y;
    son[x][!r] = y, fa[y] = x;
    son[z][son[z][1]==y] = x, fa[x] = z;
    if( y == root ) root = x;
    up( y );
}
void Splay( int x, int goal )
{
    int y, z;
    while( fa[x] - goal )
    {
        y = fa[x], z = fa[y];
        if( z == goal ) Rotate( x );
        else if( ( son[y][1] == x ) ^ ( son[z][1] == y ) )
            Rotate( x ), Rotate( x );
        else
            Rotate( y ), Rotate( x );
    }
    up( x );
}
  
void Select( int k, int goal )
{
    int p = root;
    while( 1 ){
        if( cnt[ls] + 1 == k ) break;
        if( cnt[ls] >= k ) p = ls;
        else
            k -= cnt[ls] + 1, p = rs;
    }
    Splay( p, goal );
}
int getxy( int l, int r )
{
    Select( l, 0 );
    Select( r + 2, root );
    return son[son[root][1]][0];
}
char str[M];
  
int build( int l, int r, int f )
{
    if( l > r ) return 0;
    int m = ( l + r ) >> 1;
    int p = newNode( str[m] );
    fa[p] = f;
    son[p][0] = build( l, m - 1, p );
    son[p][1] = build( m + 1, r, p );
    up( p );
    return p;
}
void insert( int k, int v )
{
    Select( k + 1, 0 );
    Select( k + 2, root );
    int p = son[root][1];
    int x = newNode( v );
    son[p][0] = x, fa[x] = p;
    Splay( x, 0 );
}
void del( int k )
{
    Select( k, 0 );
    Select( k + 2, root );
    int p = son[root][1];
    son[p][0] = 0;
    Splay( p, 0 );
}
  
int check( int k, int mid )
{
    int x = getxy( k, k + mid );
    int tmp1 = rht[x];
    x = getxy( k - mid, k );
    int tmp2 = lft[x];
    return tmp1 == tmp2;
}
int query( int k )
{
    int l = 0, r = min( k - 1, cnt[root] - 2 - k ), mid;
    while( r > l ){
        mid = ( l + r + 1 ) >> 1;
        if( check( k, mid ) ) l = mid;
        else r = mid - 1;
    }
    return l<<1|1;
}
  
int main()
{
    bit[0] = 1;
    for( int i = 1; i < M; ++i ) bit[i] = bit[i-1] * 133; //hash
    char op[10];
    int x, u, n, ans;
    while(~scanf("%s",str))
    {
        init();
        scanf( "%d", &n );
        x = son[root][1];
        u = son[x][0] = build(0,strlen( str )- 1, x );
        Splay( u, 0 );
        while( n-- )
        {
            scanf( "%s%d", op, &u );
            if( op[0] == 'I' )//Insert  
            {
                scanf( "%s", op );
                insert( u, op[0] );
            }
            else if( op[0] == 'D' )//Delete  
            {
                del( u );
            }
            else if( op[0] == 'U' )//Update  
            {
                scanf( "%s", op );
                insert( u, op[0] );
                del( u );
            }
            else //Query  
            {
                ans = query( u );
                printf( "%d\n", ans );
            }
        }
    }
    return 0;
}