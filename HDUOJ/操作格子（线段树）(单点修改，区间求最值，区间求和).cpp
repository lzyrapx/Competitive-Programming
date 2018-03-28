//http://blog.csdn.net/liangzhaoyang1/article/details/60775963
#include<bits/stdc++.h>
using namespace std;
int n,m;
#define lson l , mid , rt << 1
#define rson mid+1 , r, rt<<1|1
int sum[200000<<2];
int MAX[200000<<2];
void pushup(int rt)
{
	sum[rt]=sum[rt<<1] + sum[rt<<1|1];
	MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);	
}
void build(int l,int r,int rt)
{
	if(l==r){
		cin>>sum[rt];
		MAX[rt]=sum[rt];return ;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt); 
}
void update(int x,int y,int l,int r,int rt)
{
	if(l==r){
		//cout<<"MAX[rt]="<<MAX[rt]<<endl;
		sum[rt]=y;
		MAX[rt]=y;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)update(x,y,lson);
	else update(x,y,rson);
	pushup(rt); 
}
int query(int x,int y,int l,int r,int rt)
{
	if(x <= l && r <= y){
		return sum[rt];
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(x<=mid)ans+=query(x,y,lson);
	if(y>mid) ans+=query(x,y,rson);
	return ans; 
}
int Getmax(int x,int y,int l,int r,int rt)
{
	if(x <= l && r <= y){
		//cout<<"MAX="<<MAX[rt]<<endl;
		return MAX[rt];
	}
	int mid=(r+l)>>1;
	int ans=0;
	if(x<=mid)ans=max(ans,Getmax(x,y,lson));
	if(y>mid)ans=max(ans,Getmax(x,y,rson));
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n>>m;
    build(1,n,1);
    int op,x,y;
    while(m--){
    	cin>>op>>x>>y;
    	if(op==1){ //单点修改 
    		update(x,y,1,n,1);
		}
		if(op==2){//区间求和 
			cout<<query(x,y,1,n,1)<<endl;
		}
		if(op==3){//区间求最大值 
			cout<<Getmax(x,y,1,n,1)<<endl;
		}
	}
    
	return 0;
}