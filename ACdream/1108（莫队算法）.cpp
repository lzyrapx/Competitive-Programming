/*
* this code is made by LzyRapx
* Problem: 1108
* Verdict: Accepted
* Submission Date: 2017-06-08 21:32:50
* Time: 1716MS
* Memory: 4812KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000+10;
int mag; //定值 333~355也可以
struct Query
{
    int L,R,k,id;
    Query(int L=0,int R=0,int k=0,int id=0):L(L),R(R),k(k),id(id){}
    bool operator <(const Query &a) const
    {
        if(L/mag!=a.L/mag) return L<a.L;
        return R<a.R;
    }
}querys[maxn];
int a[maxn],num[maxn],sum[maxn],ans[maxn],n,m;
inline void Add(int pos)
{
    sum[++num[a[pos]]]++;
}
inline void Dec(int pos)
{
    sum[num[a[pos]]--]--;
}
int binary_search(int k)
{
    int l=0,r=maxn;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(sum[mid]>=k) l=mid;
        else r=mid;
    }
    return l;
}
void solve()
{
    memset(sum,0,sizeof(sum));
    memset(num,0,sizeof(num));
    int l=1,r=0;
    for(int i=0;i<m;i++)
    {
        while(r<querys[i].R) Add(++r);
        while(l>querys[i].L) Add(--l);
        while(l<querys[i].L) Dec(l++);
        while(r>querys[i].R) Dec(r--);
        ans[querys[i].id]=binary_search(querys[i].k);
    }
}
int main()
{
 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mag = sqrt(n+0.5);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&querys[i].L,&querys[i].R,&querys[i].k);
            querys[i].id=i;
        }
        sort(querys,querys+m);
        solve();
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}