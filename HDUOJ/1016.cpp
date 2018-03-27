#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>    
using namespace std;
int a[30],b[30];
int n,cas=0;
int prime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	if(x%i==0)return 0;
	return 1;
}
void dfs(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			if(prime(x+i)==1)
			{
				b[i]=1; //标志i用过 
				a[y]=i;  //储存 i 的值 
				dfs(i,y+1); //继续搜 
				b[i]=0;   //没有搜到就标志当前的 i 没用过 
			}
		}
	}
	if(y==n+1) //n+1个是结束标志 
	{
		if(prime(x+1)==1) //判断最后一个和第一个，即 1 相加是否成立 
		{
			for(int i=1;i<n;i++)
			printf("%d ",a[i]);
			printf("%d\n",a[n]);
		 } 
	}
}
int main()
{

	while(cin>>n)
	{
		printf("Case %d:\n",++cas);
		a[1]=1;
		b[1]=1;
		dfs(1,2);
		printf("\n");
	}
	return 0;
 } 