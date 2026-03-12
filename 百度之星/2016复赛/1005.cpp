#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<bitset>
#pragma comment(linker, "/STACK:1024000000,1024000000")
template <class T>
bool scanff(T &ret){ //Faster Input
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
#define inf 1073741823
#define llinf 4611686018427387903LL
#define PI acos(-1.0)
#define lth (th<<1)
#define rth (th<<1|1)
#define rep(i,a,b) for(int i=int(a);i<=int(b);i++)
#define drep(i,a,b) for(int i=int(a);i>=int(b);i--)
#define gson(i,root) for(int i=ptx[root];~i;i=ed[i].next)
#define tdata int testnum;scanff(testnum);for(int cas=1;cas<=testnum;cas++)
#define mem(x,val) memset(x,val,sizeof(x))
#define mkp(a,b) make_pair(a,b)
#define findx(x) lower_bound(b+1,b+1+bn,x)-b
#define pb(x) push_back(x)
#define count1(x) __builtin_popcountl()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



bitset<501> a[2222];

char s[8002000];
char t[555];
int n,len;
bitset<501> pre,cur;
bitset<501> *p;
bitset<501> *c;
int main(){
    while(gets(s)!=NULL){
        pre.reset();
        cur.reset();
        rep(i,0,127)a[i].reset();
        scanff(n);
        rep(i,1,n){
            scanff(len);
            scanf("%s",t);
            rep(j,0,len-1)a[t[j]].set(i);
        }
        if(n==0){
            printf("NULL\n");
            continue;
        }
        p=⪯
        c=&cur;
        pre.set(0);
        int pd=0;
        len=strlen(s);
        rep(i,0,len-1){
            *c=((*p)<<1)&a[s[i]];
            c->set(0);
            if((*c).test(n)){
                    pd=1;
                    printf("%d\n",i-n+2);
            }
            swap(p,c);
        }
        if(pd==0)printf("NULL\n");
        scanf("%*c");
    }
    return 0;
}