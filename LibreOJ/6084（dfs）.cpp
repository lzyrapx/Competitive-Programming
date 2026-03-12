#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
int Next[100010][2];
int vis[100010],check[100010];
void dfs(int s)
{
	vis[s] = 1;
	if(s==n){
		check[s] = 1;return ;
	}
	for(int i=0;i<=1;i++)
	{
		int nx = s + Next[s][i];
		if(nx < 1 || n < nx) continue;
		if(vis[nx]==0) dfs(nx);
		if(check[nx]) check[s] = 1;
	}
}
char ch[100010];
int tot;
void print(int x)
{
	if(x==n){
		puts(ch+1);exit(0);
	}
	if(vis[x]!=0)
	{
		puts("Infinity!");exit(0);
	}
	for(int i=0;i<=1;i++)
	{
		int nx = x + Next[x][i];
		if(nx < 1 || n < nx)continue;
		if(check[nx])
		{
			ch[++tot] = i + 'a';
			print(nx);
		 } 
	}
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Next[i][0];
	}
	for(int i=1;i<=n;i++){ 
		cin>>Next[i][1]; 
	}
	dfs(1);
	if(check[1]==0)
	{
	 	puts("No solution!");return 0;
	}
	memset(vis,0,sizeof(vis));
	print(1); 
	return 0;
}