#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std ;
typedef long long LL ;
const int maxn=120005;
#define clr( a , x ) memset ( a , x , sizeof a )

const int N = 524300 ;
int n , pos[N] ;

namespace FFT {
    struct comp {
        double r , i ;
        comp ( double _r = 0 , double _i = 0 ) : r ( _r ) , i ( _i ) {}
        comp operator + ( const comp& x ) {
            return comp ( r + x.r , i + x.i ) ;
        }
        comp operator - ( const comp& x ) {
            return comp ( r - x.r , i - x.i ) ;
        }
        comp operator * ( const comp& x ) {
            return comp ( r * x.r - i * x.i , i * x.r + r * x.i ) ;
        }
        comp conj () {
            return comp ( r , -i ) ;
        }
    } A[N] , B[N] ;
    
    const double pi = acos ( -1.0 ) ;
    void FFT ( comp a[] , int n , int t ) {
        for ( int i = 1 ; i < n ; ++ i ) if ( pos[i] > i ) swap ( a[i] , a[pos[i]] ) ;
        for ( int d = 0 ; ( 1 << d ) < n ; ++ d ) {
            int m = 1 << d , m2 = m << 1 ;
            double o = pi * 2 / m2 * t ;
            comp _w ( cos ( o ) , sin ( o ) ) ;
            for ( int i = 0 ; i < n ; i += m2 ) {
                comp w ( 1 , 0 ) ;
                for ( int j = 0 ; j < m ; ++ j ) {
                    comp& A = a[i + j + m] , &B = a[i + j] , t = w * A ;
                    A = B - t ;
                    B = B + t ;
                    w = w * _w ;
                }
            }
        }
        if ( t == -1 ) for ( int i = 0 ; i < n ; ++ i ) a[i].r /= n ;
    }
    void mul ( int *a , int *b , LL *c ,int k) {
        int i , j ;
        for ( i = 0 ; i < k ; ++ i ) A[i] = comp ( a[i] , b[i] ) ;
        j = __builtin_ctz ( k ) - 1 ;
        for ( int i = 0 ; i < k ; ++ i ) {
            pos[i] = pos[i >> 1] >> 1 | ( ( i & 1 ) << j ) ;
        }
        FFT ( A , k , 1 ) ;
        for ( int i = 0 ; i < k ; ++ i ) {
            j = ( k - i ) & ( k - 1 ) ;
            B[i] = ( A[i] * A[i] - ( A[j] * A[j] ).conj () ) * comp ( 0 , -0.25 ) ;
        }
        FFT ( B , k , -1 ) ;
        for ( int i = 0 ; i < k ; ++ i ) {
            c[i] = ( long long ) ( B[i].r + 0.5 )  ;
        }
    }
}

int a[maxn];
int ne[maxn];
int no[maxn];
int l[maxn],r[maxn];
int que[maxn];
void init(int n){
    int tot=0;
    for(int i=1;i<=n;i++){
        while(tot&&a[que[tot-1]]<=a[i]) tot--;
        if(tot==0) l[i]=0;
        else l[i]=que[tot-1];
        que[tot++]=i;
    }
    tot=0;
    for(int i=n;i>=1;i--){
        while(tot&&a[que[tot-1]]<=a[i]) tot--;
        if(tot==0) r[i]=n+1;
        else r[i]=que[tot-1];
        que[tot++]=i;
    }
}
int vis[maxn];
LL z[maxn];
vector<int>g;
int x[maxn<<2],y[maxn<<2];
LL q[maxn<<2];
int main()
{
    int n,t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        memset(z,0,sizeof(z));
        memset(no,0,sizeof(no));
        init(n);
        for(int i=n;i>=1;i--){
            ne[i]=i;
            if(no[a[i]]) ne[i]=no[a[i]];
            no[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int cnt=0;
            int w=i;
            g.clear();
            int pre=l[i];
            while(ne[w]!=w&&ne[w]<=r[w]){
                x[cnt++]=w-pre;
                g.push_back(w);
                vis[w]=1;
                pre=w;
                w=ne[w];
            }
            g.push_back(w);
            vis[w]=1;
            x[cnt++]=w-pre;
            pre=r[w];
            int p=g.size();
            for(int j=p-1;j>=0;j--){
                y[p-1-j]=pre-g[j];
                pre=g[j];
            }
            w=1;
            while(w<=p) w=w*2;
            w=w*2;
            for(int j=p;j<=w;j++){
                x[j]=y[j]=0;
            }
            FFT::mul(x,y,q,w);
            for(int j=0;j<p;j++){
                z[p-j]+=q[j];
            }
        }
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans+=i^z[i];
        }
        printf("%lld\n",ans);
    }
}