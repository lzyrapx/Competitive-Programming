#include<bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int maxn =11111;
int sum[maxn<<2];
int L[maxn<<2],R[maxn<<2];
int cnt = 0;
int x[maxn];
/*
例子：1 2 1 0
序列应该是：2 4 5 3 1
解析：从后往前推，假如排在最后的一头牛比他编号小的数量为a，那么它的编号必然为a+1。我们把编号为a+1的这头牛删掉，
假如排在倒数第二的一头牛比他编号小的数量为b，那么该牛就为删掉编号后剩余牛中的第b+1头牛，我们可以照此思路下去...
问题就可以转化为搜索排在第k位的数为多少，我们可以用线段树来实现。
用线段树维护区间内数的个数，开始与区间长度相同，后来每次从最后往前更新，对应叶子节点的区间值变为0,可以说是查询区间第k大
*/
void push_up(int rt)
{
	//线段树维护的是区间的和，区间的和代表有几个数
	//更新查询时可以判断第几大  
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		 //区间初始化为区间的长度
		sum[rt] = (r-l+1);
		return ;
	}
	int mid = (l+r)>>1;
	build(lson);
	build(rson);
	push_up(rt); //向上更新  
}
void update(int val,int l,int r,int rt)
{
	if(l==r)
	{
		//每次更新，这个数就被用过了，下次不再用
		//所以这个叶子节点赋值为 0
		sum[rt] = 0;
		//记录当前第val大的数为 l  
		L[cnt++] = l;
		return ;
	}
	int mid = (l+r)>>1;
	//区间记录的是区间内数字的个数，val表示第val大的数,也就是val个数，
	//若val比左儿子区间的个数少，说明这个数在左儿子里
	if(val<=sum[rt<<1]) update(val,lson);
	//否则要减去左儿子的个数，在右儿子里找 第val-sum[rt<<1]大的
	else update(val-sum[rt<<1],rson);
	//向上更新 
	push_up(rt);
}
int query(int l,int r,int rt)
{
	//这次询问的目的在于找到排在第一位的数，
	//因为他前面不存在数，也就没有比它小的的数，
	//所以该叶子节点始终没有被更新，值始终为1,只要找到这个一就行
	if(l==r){
		return l;
	}
	int mid = (l+r)>>1;
	int ans = 0;
	//左儿子区间等于1,往左儿子里查找
	if(sum[rt<<1] == 1) ans = query(lson);
	//否则往右儿子里查找
	else ans = query(rson);
	return ans ;
 } 
int main()
{
	int n;
	while(cin>>n)
	{
		cnt = 0;
		memset(L,0,sizeof(L));
		build(1,n,1);
		for(int i=0;i<n-1;i++) cin>>x[i];
		for(int i=n-2;i>=0;--i){
			//从最后一位的开始更新  
			update(x[i]+1,1,n,1);
		}
		//询问第一位的标号 
		printf("%d\n",query(1,n,1));
		for(int i=cnt-1;i>=0;--i)
		{
			cout<<L[i]<<endl;
		}
	}
	return 0;
 } 