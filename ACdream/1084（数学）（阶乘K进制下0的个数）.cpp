/*
* this code is made by LzyRapx
* Problem: 1084
* Verdict: Accepted
* Submission Date: 2017-06-19 23:12:01
* Time: 60MS
* Memory: 6572KB
*/

/*
就是让你求A(n,m)的K进制下末尾0的个数。 
K太大，显然不能直接模。 
A(n,m)转换成k进制有多少个零相当于它能连续被几个k整除， 
将K进行素因子分解，然后计算每个素因子在n!−(n−m)!中的指数，那么每个素因子在n!−(n−m)!中的指数除以K 分解出来的指数，取其最小值就是答案了。

问题可以从阶乘 n! 的K进制下末尾0的个数转换而来。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
 
int prime[maxn];//素数 
int cnt;
int fac[1234]; //素因子 
int num;
int expo[1234];//K的指数 
bool vis[maxn];
ll res;
void init()
{
    memset(vis,0,sizeof(vis));
    cnt = 0;
    for(int i = 2; i<maxn;i++)
    {
        if(!vis[i]){
            prime[cnt++] = i;
            for(int j = i+i;j<maxn;j+=i){
                vis[j] = 1;
            }
        }
    }
}
void getfactor(int x)
{
    num = 0;
    memset(expo,0,sizeof(expo));
    int n=sqrt(x);
    for(int i=0;i<cnt && prime[i]<=n;i++)
    {
        if(x%prime[i]==0)
        {
            fac[num] = prime[i];  
            while(x%prime[i]==0){
                expo[num]++;//K的指数 
                x/=prime[i];
            }
            num++;
        }
    }
    if(x>1){
        fac[num] = x;
        expo[num++] = 1;
    }
}
ll solve(int n,int p)
{
    if(n<p)return 0;
    return solve( n / p , p) + 1LL* n / p;
}
int main()
{
    init();
    int t,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k; 
        getfactor(k);//将 k 素因子分解 
        ll ans = 1e9;
    //  cout<<"num="<<num<<endl; 
        for(int i=0;i<num;i++)
        {
            res = solve(n,fac[i]) - solve(n-m,fac[i]);//每个素因子在 n!-(n-m)!中的指数 
        //  cout<<"res="<<res<<endl;
        //  cout<<"expo="<<expo[i]<<endl;
            ans = min(res / expo[i], ans); 
        }
        cout<<ans<<endl;
    }
    return 0;
}