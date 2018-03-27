#include <stdio.h>
#define maxn 222222

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int MAX[maxn<<2];

int max(int a,int b)
{
    return a>b? a:b;
}

void PushUP(int rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

void Build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUP(rt);
}



int Query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return MAX[rt];
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)   ret=max(ret,Query(L,R,lson));
    if(R>m)    ret=max(ret,Query(L,R,rson));
    return ret;
}

int main()
{
    int N,M;
    char s[5];
    while(~scanf("%d",&N))
    {
        Build(1,N,1);
        scanf("%d",&M);
        while(M--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
        	printf("%d\n",Query(a+1,b+1,1,N,1));
        }
    }
    return 0;
}