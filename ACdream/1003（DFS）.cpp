/*
* this code is made by LzyRapx
* Problem: 1003
* Verdict: Accepted
* Submission Date: 2017-06-23 14:55:58
* Time: 140MS
* Memory: 1676KB
*/

/*
首先算出来所有数字的和， 然后判断是否有解。分k奇偶枚举公差之后，排序，就开始dfs搜索。
需要的剪枝：
1、  如果每一堆的最小项小于药片的最小项 false
2、  如果当前一堆枚举的和sum加上剩下药片的最小大于当前堆的容量 false
3、  如果当前堆正好放下一大块药片，放
4、  如果搜索到某一个药片，并且前一个药片已经搜索过+前一个药片和当前一个大小一样，跳过（重要剪枝）
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
#define mod 1000000007
int n,m,sum;
int Min,res;
int pill[23];
int vis[23];
vector<int> q;
bool flag;
void dfs(int ii,int val,int index)
{
     
    if(val<Min) return;
    for(int i=ii;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(flag) return;
            if(i>1 && pill[i]==pill[i-1] && vis[i-1]==0) continue;
            if(pill[i]>val) return;
            vis[i]=1;
            if(pill[i]==val)
            {
                if(index==q.size()-1)
                {
                    flag=true;
                    return;
                }
                dfs(1,q[index+1],index+1);
            }
            else dfs(i+1,val - pill[i],index);
            vis[i]=0;
        }   
    } 
     
}
bool solve(int x,int ge)
{
    int tmp=x;
    memset(vis,0,sizeof(vis));
    q.clear();
    flag=false;
    for(int i=1;i<=m;i++)
    {
       bool f1=false;
       for(int j=1;j<=n;j++)
       {
            if(pill[j]>tmp) break;
            if(vis[j]==0 && tmp==pill[j])
           {
                f1=true;
                vis[j]=1;
                break; 
            }
      }
      if(!f1)
      {
        q.push_back(tmp);  
      }
      tmp+=ge;
    }
    if(q.empty()) return 1;
    dfs(1,q[0],0);
    return flag;
}
int main()
{
    int t,yue;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        sum=0; 
        Min=10000;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&pill[i]);
            sum+=pill[i];
            Min=min(Min,pill[i]);
        }
        sort(pill+1,pill+n+1);
        if(m==0)
        { 
            puts("Impossible");
            continue;
        }
        if(n==1 || m==1)
        {   
            printf("0\n"); 
            continue; 
        }
        //算出总和SUM，等差数列得到的sum肯定是二元一次方程，解为大于0的整数解
        yue= m > (m * (m - 1) / 2)? __gcd(m, m*(m-1)/2):__gcd(m*(m-1)/2,m);
        if(sum % yue!=0 || 2 * sum % m!=0)
        { 
            puts("Impossible"); 
            continue;
        }
        res=-1;
        for(int i=0; i <=2 * sum / m - 2; i += (m-1))
        {
              
          int ge= i / (m-1);
          if((sum - m * (m-1) / 2 * ge) % m!=0) continue;
          int x=(sum - m * (m-1) / 2 * ge) / m;
          if(x >= pill[1] && x + (m-1) * ge >= pill[n] && solve(x,ge))
          {
            res=ge;
            break;
          }
        }
        if(res==-1) puts("Impossible");
        else printf("%d\n",res);
    }
    return 0;
}