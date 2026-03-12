/*
* this code is made by LzyRapx
* Problem: 1076
* Verdict: Accepted
* Submission Date: 2017-07-20 10:28:40
* Time: 924MS
* Memory: 7532KB
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=123456;
int p[8];
int sx[maxn][6],sy[maxn][6];
//dp[i][j]表示指令为 i 时，全排列状态为 j 
int dp[123][150];
int op_s[123];
int op_t[123];
int id[150][6];
void init()
{
    p[0]=1;
    for(int i=1;i<=5;i++) p[i]=p[i-1]*i;
    int a[6],cnt=0;
    for(int i=1;i<=5;i++) a[i]=i;
    do{
        cnt++;
        for(int i=1;i<=5;i++){
            id[cnt][i]=a[i];
        }
    }while(next_permutation(a+1,a+6));
}
int Cantor(int a[])//康拓展开 
{
    int res=0,tmp;
    for(int i=1;i<=5;i++)
    {
        tmp=a[i]-1;
        for(int j=1;j<i;j++) if(a[j]<a[i]) tmp--;
        res+=tmp*p[5-i];
    }
    return res+1;
}
void cal(int a[],int b[],int c[])
{
    for(int i=1;i<=5;i++)
        c[i]=b[a[i]];
}
void cal2(int a[],int b[])
{
    for(int i=1;i<=5;i++)
        b[a[i]]=i;
}
int main()
{
    init();//预处理全排列 
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=5;i++)
        {
            sx[0][i]=sy[n+1][i]=i;
        }

        int a[6],b[6];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                scanf("%d",&sy[i][j]);
            }  
            cal(sx[i-1],sy[i],sx[i]);
        }
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=5;j++)
            {
                a[j]=sy[i][j];
            }     
            cal(sy[i+1],a,sy[i]);
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&op_s[i],&op_t[i]);
        }

        for(int i=1;i<=5;i++)
        {
            scanf("%d",&a[i]);//初始卡片 
        }        
        memset(dp,0x3f,sizeof(dp));
        int x;
        int s,t;
        x=Cantor(a);
       // cout<<"x="<<x<<endl; 
        dp[0][x]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=120;j++)
            {
                if(dp[i][j]==0x3f3f3f3f) continue;
                dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
                s=op_s[i+1];
                t=op_t[i+1];
                if(s < t)
                {
                    cal2(sx[s-1],b);
                    cal(b,sx[t],a);
                    cal(id[j],a,b);
                    x=Cantor(b);
                    dp[i+1][x] = min(dp[i+1][x],dp[i][j] + t - s + 1);
                }
                else
                {
                    cal2(sy[s+1],b);
                    cal(b,sy[t],a);
                    cal(id[j],a,b);
                    x=Cantor(b);
                    dp[i+1][x] = min(dp[i+1][x],dp[i][j] + s - t + 1);
                }
            }
        }       
        int ans=dp[m][1];
        if(ans==0x3f3f3f3f) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
} 