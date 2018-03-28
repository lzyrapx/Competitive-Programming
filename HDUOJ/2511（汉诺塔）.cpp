#include<bits/stdc++.h>
using namespace std;
//从from借助 mid 移到 to 
void solve(int l,int r,long long m,int from,int to,int mid)
{
	long long num = (1LL<<(r-l))-1;
	if(m<=num)//从from柱子以mid为中介放到to 
	{
		solve(l,r-1,m,from,mid,to);	
	} 
	else if(m==num+1){
		printf("%d %d %d\n",r,from,to);
	}
	else //把最下面的碟子放到to上
	{
		solve(l,r-1,m-1-num,mid,to,from);
	}
}
int main()
{
	int t,n;
	long long m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;// n 个盘子，第 m 次移动 
		solve(1,n,m,1,3,2);
	 } 
	return 0;
 } 