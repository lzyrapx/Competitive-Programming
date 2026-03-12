#include<iostream>   
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=100;
char a[1005];  
char b[1005];  
int dp[1005][1005];  
int pre[1005][1005];  
  
void dfs(int m,int n)  
{  
    if(m==0||n==0)  
        return;  
    if(pre[m][n]==1)  
    {  
        dfs(m-1,n-1);  
        cout<<a[m];  
    }  
    else if(pre[m][n]==2)  
    {  
        dfs(m-1,n);  
    }  
    else  
    {  
        dfs(m,n-1);  
    }  
} 
int main()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
	//string a,b;
	cin>>a+1>>b+1;
	for(i=1;i<=strlen(a+1);i++)
	{
		for(j=0;j<=strlen(b+1);j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				pre[i][j]=1;
			}
			else
			{
				if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j];
					pre[i][j]=2;
				}
				else
				{
					dp[i][j]=dp[i][j-1];
					pre[i][j]=3;
				}
			}
			
		}
	}
	dfs(strlen(a+1),strlen(b+1));
	cout<<endl;
	return 0;
 } 