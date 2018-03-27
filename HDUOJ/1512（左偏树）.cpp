#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int l,r;
	int dis;
	int val;
}ltree[100005];
int par[100005];
int getfather(int x)
{
	return par[x] == x?x:par[x]=getfather(par[x]);
}
int merge(int x,int y)//返回合并后的根
{
	int l,r;
	//插入的树为空时直接返回x (y)，也就是合并完的树
	if(x==0)return  y;
	if(y==0)return  x;
	if(ltree[x].val<ltree[y].val)  //大顶堆
	{
		swap(x,y);
	}
	ltree[x].r = merge(ltree[x].r,y);//递归合并右子树 和 y
	l = ltree[x].l;
	r = ltree[x].r;
	par[r] = x; //并查集合并，更新右子树的根 
	
	if(ltree[l].dis<ltree[r].dis)
	{
		//必须遵守左偏树的性质，左节点的距离不小于右节点的距离
		swap(ltree[x].l,ltree[x].r);
	}
	if(ltree[x].r==0)//如果没有右子树 则距离为0
	{
		ltree[x].dis = 0;
	} 
	else ltree[x].dis = ltree[ltree[x].r].dis+1;
	return x;
}
int pop(int x)//返回删除根以后左右子树合并的根
{
	int l,r;
	l = ltree[x].l;
	r = ltree[x].r;
	//因为要暂时删掉根，所以左右子树先作为根  
	par[l] = l;
	par[r] = r;
	ltree[x].l = 0;
	ltree[x].r = 0;
	ltree[x].dis = 0;
	return merge(l,r); 
}
int main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&ltree[i].val);
			ltree[i].l = 0;
			ltree[i].r = 0;
			ltree[i].dis = 0;
		}
		for(int i=1;i<=n;i++)par[i] = i;
		scanf("%d",&m);
		int a,b;
		int fa,fb;
		int l,r;
		while(m--)
		{
			
			scanf("%d%d",&a,&b);
			fa = getfather(a);
			fb = getfather(b);
			if(fa==fb)puts("-1");
			else
			{
				//单挑后减半 
				ltree[fa].val /= 2;
				ltree[fb].val /= 2;
				//删除最大的两个值，再与新的值合并 
				l = pop(fa),r=pop(fb);
				l = merge(l,fa);
				r = merge(r,fb);
				l = merge(l,r);
				printf("%d\n",ltree[l].val); 
			}
		}
	}
	return 0;
}