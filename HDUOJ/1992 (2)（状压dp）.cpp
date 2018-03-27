#include<bits/stdc++.h>
using namespace std;

int dp[1005][16];
//dp[i][s]表示处理完前i行,第i行状态为s的方法数.
void dfs(int r,int c,int cur,int nex)
//分别表示当前行，当前列,当前状态，可转移的状态
{
    if(c>3) //一行已经处理完 
    {
        dp[r+1][nex] += dp[r][cur];
        return;
    }
    if(cur&(1<<c) )
    {
    	dfs(r,c+1,cur,nex);   //位置被上一行的占用    
    }
    else
	{
    	dfs(r,c+1,cur,nex|(1<<c));   //竖着放，用1
        if(c<=2 && !(cur & (1<<(c+1))))
            dfs(r,c+2,cur,nex);  //横着放，两个0
	} 
}

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int i,j;
    for(i=0;i<22;i++)   //22已经爆int32了
        for(j=0;j<16;j++)
            if(dp[i][j])
                dfs(i,0,j,0);

    int t,n;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
    	printf("%d %d\n",cas++,dp[n][0]);
	}
    return 0;
}
