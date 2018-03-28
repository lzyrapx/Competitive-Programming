//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100010;
int n,m;
int a[N],b[N];
int lson[N*20],rson[N*20],sum[N*20],root[N];
int tot;
void build(int l,int r,int &rt)//建立空树，节点均为 0 
{
	rt=(++tot);
	sum[rt] = 0;
	if(l==r)return ;
	int mid =(l+r)>>1;
	build(l,mid,lson[rt]);
	build(mid+1,r,rson[rt]);
}
void update(int pre ,int &rt,int l,int r,int val)//sum[i]储存的是它所管辖区间内元素出现的次数，即[l,r]区间 
{
	rt=(++tot);
	lson[rt]=lson[pre];
	rson[rt] = rson[pre];
	sum[rt] = sum[pre] + 1;
	if(l == r) return;  
    int mid = (l + r) >> 1;  
    if(val <= mid) 
	update(lson[pre], lson[rt], l, mid, val); //此元素在左区间  
    else 
	update(rson[pre], rson[rt], mid + 1, r, val);//右区间 
}

int query(int ss, int tt, int l, int r, int k) //返回值是第k大数在离散去重后的数组中的下标，线段树管理的区间是离散后的区间  
{ 
    if(l == r) return l; //此时无论k值，我们确定k就在[l,r]区间中，又l==r，结果求出  
    int mid = (l + r) >> 1;  
    int tmp = sum[lson[tt]] - sum[lson[ss]]; //左区间内元素个数
	//要查询第k大数，先求左区间内元素的个数tmp，tmp >= k，直接查询左区间内的第k大，否则查询右区间内的第k-tmp大   
    if(tmp >= k) return query(lson[ss], lson[tt], l, mid, k);
    else return query(rson[ss], rson[tt], mid + 1, r, k - tmp);  
}  
int main()
{
	int t ;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		tot = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		int len =unique(b+1,b+1+n)-b-1;
		build(1,len,root[0]);
		for(int i=1;i<=n;i++)
		{
			a[i]=lower_bound(b+1,b+1+len,a[i])-b;
			update(root[i-1],root[i],1,len,a[i]);
		}
		while(m--)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",b[query(root[l-1],root[r],1,len,k)]);
		}
	}
	return 0;
}