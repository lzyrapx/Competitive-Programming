#include<bits/stdc++.h>
using namespace std;
const long long INF = 0x7ffffffffll;
long long ans;
long long n;
bool solve(long long x) //判断这个数满不满足条件 
{
    if(x<2)
        return false;
    long long t=x;
    for(long long i=2;i*i<=x;i++) //暴力枚举质因数分解式 
    {
        if(x%i==0)
        {
            if(x%(i*i)==0) //出现了超过一次
            {
                return false;
            }
            x/=i;
        }
    }
    ans=min(ans,abs(t*t-n)); //最小绝对值 :y-x=(t^2-n) 
    return true;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        long long x=(long long)(sqrt(n)+0.5);
        int flag=0;
        ans=INF;
        for(int i=0; ;i++)
        {
            if(solve(x+i))
                flag=1;
            if(solve(x-i))
                flag=1;
            if(flag==1)
                break;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}