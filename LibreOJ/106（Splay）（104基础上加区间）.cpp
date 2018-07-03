#include<cstdio>
#include<algorithm>
using namespace std;

#define L tree[t][0]
#define R tree[t][1]
using namespace std;
const int inf=1e9+10;
const int maxn=5e4+10;
const int maxnodes=maxn*30;
int n,m;
int left,right;
int qc,qv,A[maxn];

int tot,root[maxn*4],fa[maxnodes],val[maxnodes],size[maxnodes],tree[maxnodes][2];
	
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
	int f=fa[t],x=side(t,f),s=tree[t][x^1],y=side(f,fa[f]);
	fa[t]=fa[f]; tree[fa[f]][y]=t; fa[s]=f; tree[f][x]=s;
	fa[f]=t; tree[t][x^1]=f; Update(f); Update(t);
}
void Splay(int t,int y,int &rt)
{
	while(fa[t]!=y)
	{
		if(side(t,fa[t])==side(fa[t],fa[fa[t]]) && fa[t]!=rt && fa[fa[t]]!=rt)Rotate(fa[t]);
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
	if(!t){t=++tot; size[t]=1; val[t]=qc; fa[t]=f; return;}
	if(qc<=val[t])InsertY(L,t); else InsertY(R,t); Update(t);
}
void InsertX(int t,int l,int r)
{
	InsertY(root[t],0); Splay(tot,0,root[t]);
	if(l==r)return; int mid=(l+r)>>1;
	if(qv<=mid)InsertX(t<<1,l,mid);
	else InsertX(t<<1|1,mid+1,r);
}
void DeleteY(int &rt)
{
	int t=Find(rt,qc); Splay(t,0,rt);
	int pre=Pre(L),suc=Suc(R);
	Splay(pre,0,rt); Splay(suc,pre,rt);
	tree[suc][0]=0; fa[t]=0;
	Update(suc); Update(pre);
}
void DeleteX(int t,int l,int r)
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
int RankX(int t,int l,int r)
{
	if(left<=l && r<=right)return RankY(root[t])-1;
	int mid=(l+r)>>1;
	if(right<=mid)return RankX(t<<1,l,mid);
	else if(left>mid)return RankX(t<<1|1,mid+1,r);
	return RankX(t<<1,l,mid)+RankX(t<<1|1,mid+1,r);
}
int NumbX()
{
	int lx=0,rx=inf,ans;
	while(lx<=rx)
	{
		qc=(lx+rx)>>1; int ret=RankX(1,1,n)+1;
		if(qv<ret)rx=qc-1; else lx=qc+1,ans=qc;
	}
	return ans;
}
int PreY(int t)
{
	if(!t)return -inf;
	if(qc<=val[t])return PreY(L);
	return max(val[t],PreY(R));
}
int PreX(int t,int l,int r)
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
int SucX(int t,int l,int r)
{
	if(left<=l && r<=right)return SucY(root[t]);
	int mid=(l+r)>>1;
	if(right<=mid)return SucX(t<<1,l,mid);
	else if(left>mid)return SucX(t<<1|1,mid+1,r);
	return min(SucX(t<<1,l,mid),SucX(t<<1|1,mid+1,r));
}
void Build(int t,int l,int r)
{
	qc=inf; InsertY(root[t],0);
	qc=-inf; InsertY(root[t],0);
	if(l==r)return; int mid=(l+r)>>1;
	Build(t<<1,l,mid);
	Build(t<<1|1,mid+1,r);
}	


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
		if(op==1) //查询排名 
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",RankX(1,1,n)+1);
		}
		if(op==2)
		{
			scanf("%d%d%d",&left,&right,&qv);
			printf("%d\n",NumbX());
		}
		if(op==3)
		{
			scanf("%d%d",&x,&y);
			
			qv=x; qc=A[x]; 
			DeleteX(1,1,n);
			
			qv=x; qc=y; 
			InsertX(1,1,n); 
			A[x]=y;
		}
		if(op==4)
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",PreX(1,1,n));
		}
		if(op==5)
		{
			scanf("%d%d%d",&left,&right,&qc);
			printf("%d\n",SucX(1,1,n));
		}
	}
	return 0;
} 