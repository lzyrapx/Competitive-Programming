#include <bits/stdc++.h>
using namespace std;
const int maxn = 56789;
int n,m,k,t;
int times[maxn<<2],a[maxn],bl[maxn],num[maxn],cnt[maxn],ret[maxn];
bool vis[maxn<<2];
int all;
struct node
{
    int l,r,x;
	int id,block;
    bool operator<(const node&p)const
    {
        return block == p.block? r < p.r : block < p.block;
    }
}querys[maxn];
void ins(int x)
{
    ++num[++cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]-1];
}
void del(int x)
{
    ++num[--cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]+1];
}
int main()
{
    scanf("%d%d",&n,&m);
    int sz=(int)sqrt(n);
    for(int i=1;i<=n;i++)
    {
    	bl[i]=(i-1)/sz+1;
	}
  	for(int i=1;i<=n;i++){
  		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&querys[i].l,&querys[i].r,&querys[i].x);
        querys[i].id = i;
		querys[i].block = bl[querys[i].l];
    }
    sort(querys+1,querys+m+1);
    //for(int i=1;i<=m;i++){
    //	printf("%d %d %d\n",querys[i].l,querys[i].r,querys[i].x); 
//	}
    int l = 1 , r = 0;
    for(int i = 1 ; i <= m; i++)
    {
        while(r<querys[i].r)ins(a[++r]);
        while(l>querys[i].l)ins(a[--l]);
        while(r>querys[i].r)del(a[r--]);
        while(l<querys[i].l)del(a[l++]);
        
        int k=0,ans=0;
        for(int j=1;j <= all;j++)
        {
            if(!vis[times[j]]&&num[times[j]]>0)
            {
                if(__gcd(times[j],querys[i].x)==1)
                {
                    ans+=num[times[j]];
                }
                times[++k]=times[j];
				vis[times[j]]=true;
            }
        }
        all=k;
        for(int j=1;j<=k;j++){
        	vis[times[j]] = false;
		}
        ret[querys[i].id]=ans;
    }
    for(int i=1;i<=m;i++) printf("%d\n",ret[i]);
    return 0;
}