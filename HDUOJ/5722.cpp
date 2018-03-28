#include<stdio.h>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=100010;
typedef long long LL;
typedef unsigned long long ull;
vector<int>f[N];
int a[N],b[N],l[N],r[N],pre[N];
//题意：给定n个数和x，求有多少个区间满足这个区间中至少有一个数恰好出现次数为x。
//分析：我们枚举区间的右边界，然后会发现可行位置是若干数的可行域的并，每向右移动一位可能改变一个数的可行域，
//我们只需要将它的可行域与之前的取并就是了，要求取线段的并和添加删除线段，用线段树处理就行了，想扫描线那样。
void deal(int n,int x) {
    int i,g;
    sort(b+1,b+n+1);
    g=unique(b+1,b+n+1)-(b+1);
    for (i=1;i<=n;i++) a[i]=lower_bound(b+1,b+g+1,a[i])-b;
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(pre,0,sizeof(pre));
    for (i=1;i<=n;i++) f[i].clear();
    for (i=1;i<=n;i++) {
        if (f[a[i]].size()>0) pre[i]=f[a[i]][f[a[i]].size()-1];
        f[a[i]].push_back(i);
        if (f[a[i]].size()>=x) r[i]=f[a[i]][f[a[i]].size()-x];
        if (f[a[i]].size()>=x+1) l[i]=f[a[i]][f[a[i]].size()-x-1];
    }
}
int sum[4*N],sig[4*N];
void updata(int x,int l,int r,int L,int R,int w) {
    if (l==L&&r==R) {
        sig[x]+=w;
        if (sig[x]) sum[x]=r-l+1;
        else if (l==r) sum[x]=0;
            else sum[x]=sum[x<<1]+sum[x<<1^1];
        return ;
    }
    int mid=(l+r)>>1;
    if (R<=mid) updata(x<<1,l,mid,L,R,w);
    else if (L>mid) updata(x<<1^1,mid+1,r,L,R,w);
        else { updata(x<<1,l,mid,L,mid,w);updata(x<<1^1,mid+1,r,mid+1,R,w); }
    if (sig[x]) sum[x]=r-l+1;
    else sum[x]=sum[x<<1]+sum[x<<1^1];
}
int main()
{
    int i,n,x,t;
    LL ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        for (i=1;i<=n;i++) scanf("%d", &a[i]),b[i]=a[i];
        deal(n,x);ans=0ll;
        memset(sig,0,sizeof(sig));
        memset(sum,0,sizeof(sum));
        for (i=1;i<=n;i++) {
            if (pre[i]&&r[pre[i]]) updata(1,1,n,l[pre[i]]+1,r[pre[i]],-1);
            if (r[i]) updata(1,1,n,l[i]+1,r[i],1);
            ans+=(LL)sum[1];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}