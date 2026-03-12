#include<bits/stdc++.h>
//#include<cstdio> 
using namespace std;
int n,m;
bool vis[23],mark[23];
int len,ans,flag; 
int bit[23];
// 这道题其实就是在一个数字串中加空格，所以开一个mark数组标记每一位前是否要加空格，
// 搜索的时候对每一位都有两种情况，即将该位归于上一段和将该位归于新的一段，
// 分别向下搜索两次即可，注意标记和回溯 
void dfs(int pos,int sum,int num)//
{
	if(sum + num > n) return;//不满足条件
	if(len == pos)
	{
		sum += num;
		if(sum <= n && sum > ans)//更新答案
		{
			ans = sum;
			flag = false;
			for(int i = 0;i < len;i++)
			{
				vis[i] = mark[i];	
			}	
			return;
		}
		if(ans == sum)//多组解
		{
			flag = true;	
		}
		return;
	}
	dfs(pos+1,sum,num*10+bit[pos]);//将pos位归到这一段 
	mark[pos] = true;//标志是否加空格
	dfs(pos+1,sum+num,bit[pos]);//将pos位归到下一段  
	mark[pos] = false;//回溯 
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)break;
		flag = len = ans =0;
		memset(mark,false,sizeof(mark));
		int tmp[11];
		while(m)
		{
			tmp[len++]=m%10;
			m/=10;
		}
		for(int i=0;i<len;i++)
		{
			bit[len-i-1]=tmp[i];
		}
		dfs(1,0,bit[0]);
		if(ans==0)// 无解 
		{
			puts("error");
		}
		else if(flag)//多组解 
		{
			puts("rejected"); 
		}
		else//唯一解 
		{
			printf("%d ",ans);
			for(int i=0;i<len;i++)
			{
				if(vis[i])//判断每一位是否要加空格 
				{
					printf(" ");
				}
				cout<<bit[i];
			}
			cout<<endl;
		}
	}
	return 0;
} 