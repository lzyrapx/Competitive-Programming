#include<bits/stdc++.h>
using namespace std;
bool vis[567][567];
char s1[567],s2[567],s3[567];
bool flag;
void dfs(int i,int j,int k)
{
	if(vis[i][j]==true)return;
	vis[i][j] = true;
	if(s3[k]=='\0'){
		flag =true;
		return;
	}
	if(s1[i]==s3[k] && s2[j]==s3[k])
	{
		dfs(i+1,j,k+1);
		dfs(i,j+1,k+1);
	}
	else if(s1[i]==s3[k] && s2[j]!=s3[k])
	{
		dfs(i+1,j,k+1);
	}
	else if(s1[i]!=s3[k] && s2[j]==s3[k])
	{
		dfs(i,j+1,k+1);
	}
	else return;
}
/*
3
cat tree tcraete
cat tree catrtee
cat tree cttaree

Data set 1: yes
Data set 2: yes
Data set 3: no
*/
int main()
{
	int t;
	int cas = 1;
	cin>>t;
	while(t--)
	{
		flag = false;
		memset(vis,false,sizeof(vis));
		scanf("%s%s%s",s1,s2,s3);
		dfs(0,0,0);
		printf("Data set %d: ",cas++);
		if(flag)puts("yes");
		else puts("no");
	} 
	return 0;
}