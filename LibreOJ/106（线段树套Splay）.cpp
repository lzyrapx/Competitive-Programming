#include<cstdio>
#include<algorithm>
using namespace std;
#define L tree[t][0]
#define R tree[t][1]
using namespace std;
const int inf=1e9+10;
const int maxn=5e4+10;
const int maxnodes=maxn*30;
//这个树套树就是对线段树的每个区间建一棵splay来维护 
int n,m;
int left,right;
int qc,qv,A[maxn];
//qv:排名 
//qc: 有序序列中的数 
int tot;
int root[maxn*4],fa[maxnodes],val[maxnodes];
int size[maxnodes],tree[maxnodes][2];
	
void Update(int t)
{
	size[t]=size[L]+size[R]+1;
}	
int side(int t,int f)
{	
	return tree[f][0]==t ? 0 : 1;
}
int Pre(int t)
{	
	return R ? Pre(R) : t;
}
int Suc(int t)
{	
	return L ? Suc(L) : t;
}
void Rotate(int t)
{
	int f=fa[t],x=side(t,f);
	int s=tree[t][x^1],y=side(f,fa[f]);
	fa[t]=fa[f]; tree[fa[f]][y]=t; 
	fa[s]=f; tree[f][x]=s;
	fa[f]=t; tree[t][x^1]=f;
	Update(f); 
	Update(t);
}
void Splay(int t,int y,int &rt)
{
	while(fa[t]!=y)
	{
		if(side(t,fa[t])==side(fa[t],fa[fa[t]]) && fa[t]!=rt && fa[fa[t]]!=rt)
			Rotate(fa[t]);
			
		Rotate(t);
	}
	if(y==0)rt=t;
}
int Find(int t,int x)
{
	if(x==val[t])return t;
	return x<val[t] ? Find(L,x) : Find(R,x);
}

void InsertY(int &t,int f)
{
	if(!t)
	{	
		t=++tot; size[t]=1; val[t]=qc; fa[t]=f; 
		return;
	}
	if(qc<=val[t])InsertY(L,t); 
	else InsertY(R,t); 
	Update(t);
}
void InsertX(int t,int l,int r) //插入 
{
	InsertY(root[t],0); 
	Splay(tot,0,root[t]);
	if(l==r) return; 
	int mid=(l+r)>>1;
	if(qv<=mid) InsertX(t<<1,l,mid);
	else InsertX(t<<1|1,mid+1,r);
}

void DeleteY(int &rt)
{
	int t=Find(rt,qc); 
	Splay(t,0,rt);
	int pre=Pre(L),suc=Suc(R);
	Splay(pre,0,rt); 
	Splay(suc,pre,rt);
	tree[suc][0]=0; 
	fa[t]=0;
	Update(suc); 
	Update(pre);
}
void DeleteX(int t,int l,int r)//删除 
{
	DeleteY(root[t]);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(qv<=mid)DeleteX(t<<1,l,mid);
	else DeleteX(t<<1|1,mid+1,r);
}

int RankY(int t)
{
	if(!t)return 0;
	if(qc<=val[t])return RankY(L);
	return size[L]+1+RankY(R);
}
int RankX(int t,int l,int r)//求数的排名 
{
	if(left<=l && r<=right)return RankY(root[t])-1;
	int mid=(l+r)>>1;
	if(right<=mid) return RankX(t<<1,l,mid);
	else if(left>mid) return RankX(t<<1|1,mid+1,r);
	return RankX(t<<1,l,mid) + RankX(t<<1|1,mid+1,r);
}
int NumbX() //排名为qv的值 
{
	int lx=0,rx=inf;
	int ans;
	while(lx<=rx)
	{
		qc=(lx+rx)>>1; 
		int ret=RankX(1,1,n)+1;
		if(qv<ret)rx=qc-1; 
		else
		{
			lx=qc+1;
			ans=qc;	
		}
	}
	return ans;
}

int PreY(int t)
{
	if(!t)return -inf;
	if(qc<=val[t])return PreY(L);
	return max(val[t],PreY(R));
}
int PreX(int t,int l,int r)//前驱 
{
	if(left<=l && r<=right)return PreY(root[t]);
	int mid=(l+r)>>1;
	if(right<=mid)return PreX(t<<1,l,mid);
	if(left>mid)return PreX(t<<1|1,mid+1,r);
	return max(PreX(t<<1,l,mid),PreX(t<<1|1,mid+1,r));
}

int SucY(int t)
{
	if(!t)return inf;
	if(qc>=val[t])return SucY(R);
	return min(val[t],SucY(L));
}
int SucX(int t,int l,int r)//后继 
{
	if(left<=l && r<=right)return SucY(root[t]);
	int mid=(l+r)>>1;
	if(right<=mid)return SucX(t<<1,l,mid);
	else if(left>mid)return SucX(t<<1|1,mid+1,r);
	return min(SucX(t<<1,l,mid),SucX(t<<1|1,mid+1,r));
}

void Build(int t,int l,int r)
{
	qc=inf; 
	InsertY(root[t],0);
	qc=-inf; 
	InsertY(root[t],0);
	if(l==r)return; int mid=(l+r)>>1;
	Build(t<<1,l,mid);
	Build(t<<1|1,mid+1,r);
}	
/*
操作1.寻找k在[l,r]上的排名就是求[l,r]中比k小的数的数量+1，
这等价于找出它在[l,mid]和[mid+1,r]上比他小的数的总数量+1，
然后就可以线段树一层层套下去，再用Splay的rank函数查找了。

操作2. 比较麻烦，因为它不能像1一样在区间中合并，但数据范围是[0,10^8]，
所以我们可以令l=0,r=10^8，二分查找mid的排名，最后得到正解。

操作3，这是单点修改，所以直接一直放下去，并修改所在的
区间的splay（先del原数值再insert新数值）。

操作4，5，显然答案也是可以在区间上合并的，前驱找出最大的，后继找出最小的，
一层层下放，如果查询区间覆盖了当前线段树的节点区间，就直接
调用Splay的前驱后继函数。
*/ 

int main()
{
	scanf("%d%d",&n,&m); 
	Build(1,1,n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)
	{
		qv=i;
		qc=A[i];
		InsertX(1,1,n);
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y; 
		scanf("%d",&op);
		if(op==1) //查询 qc 在区间内的排名
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",RankX(1,1,n)+1);
		}
		if(op==2) // 查询区间内排名为 qv 的值
		{
			scanf("%d%d%d",&left,&right,&qv);
			printf("%d\n",NumbX());
		}
		if(op==3) //修改某一位置上的数值
		{
			scanf("%d%d",&x,&y);// x 位置的数修改为 y
			
			qv=x; qc=A[x]; 
			DeleteX(1,1,n);
			
			qv=x; qc=y; 
			InsertX(1,1,n); 
			A[x]=y;
		}
		if(op==4)//查询 qc 在区间内的前趋
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",PreX(1,1,n));
		}
		if(op==5) //查询 qc 在区间内的后继
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",SucX(1,1,n));
		}
	}
	return 0;
} 