#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int a[N];int n;
int l[N],r[N];
LL ma[N<<2];
void add(int me,int cl,int cr,int x,int y,LL w){
    if(ma[me]>=w)return;
    if(x<=cl&&cr<=y){
        if(w>ma[me])ma[me]=w;
        return;
    }
    int mid=(cl+cr)>>1;
    if(x<=mid)add(me<<1,cl,mid,x,y,w);
    if(y>mid)add(me<<1|1,mid+1,cr,x,y,w);
}
void go(int me,int l,int r,LL x){
    if(ma[me]>x)x=ma[me];
    ma[me]=0;
    if(l==r){
        printf("%I64d\n",x);
        return;
    }
    int mid=(l+r)>>1;
    go(me<<1,l,mid,x);
    go(me<<1|1,mid+1,r,x);
}
void Main(){
    rep(i,1,n)l[i]=r[i]=0;
    rep(i,1,n)scanf("%d",&a[i]);
    l[1]=0;
    rep(i,2,n){
        int x=i-1;
        while(a[x]>=a[i]&&x)x=l[x];
        l[i]=x;
    }
    r[n]=n+1;
    per(i,n-1,1){
        int x=i+1;
        while(a[x]>=a[i]&&(x<=n))x=r[x];
        r[i]=x;
    }
    rep(i,1,n){
        for(int x=i;x!=n+1;x=r[x]){
            int R=r[x]-1;
            int L=x-i+1;
            for(int y=i;y;y=l[y]){
                if(a[y]<a[x]){
                    R=R-(y+1)+1;
                    break;
                }
            }
            add(1,1,n,L,R,a[x]*1ll*a[i]);
        }
        for(int x=i;x;x=l[x]){
            int L,R;
            L=i-x+1;
            R=n-(l[x]+1)+1;
            for(int y=i;y<=n;y=r[y]){
                if(a[y]<a[x]){
                    R=(y-1)-(l[x]+1)+1;
                    break;
                }
            }
            add(1,1,n,L,R,a[x]*1ll*a[i]);
        }
    }
    go(1,1,n,0);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        Main();
    }
    return 0;
}