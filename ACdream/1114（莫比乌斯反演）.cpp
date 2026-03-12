/*
* this code is made by LzyRapx
* Problem: 1114
* Verdict: Accepted
* Submission Date: 2017-08-28 18:47:04
* Time: 452MS
* Memory: 8612KB
*/
//http://blog.csdn.net/liangzhaoyang1/article/details/77655855
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 222222+10;
int isprime[N],mu[N],prime[N];
int cnt;
void Mobius(int n)
{
    int i,j;
    cnt=0;mu[1]=1;
    for(i=2;i<=n;i++){
        if(!isprime[i]){
            prime[cnt++]=i;
            mu[i]=-1;
        }
        for(j=0;j<cnt&& i*prime[j]<=n;j++){
            isprime[i*prime[j]]=1;
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
            else {mu[i*prime[j]]=0;break;}
        }
    }
}
int a[N];
int n;
ll ans;
ll num[N];
ll Count[N];
int main()
{
	Mobius(222222);
	while(~scanf("%d",&n))
	{
		ans = 0;
		int  Maxx = - 0x7fffffff;
        memset(Count, 0, sizeof(Count));
        memset(num, 0, sizeof(num));
		
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]); 
            Maxx = max(Maxx, a[i]);
        }

        for(int i=1;i<=n;i++){
        	++num[a[i]];
		}       
        for(int i=1;i<=Maxx;i++)
		{
        	for(int j=i;j<=Maxx;j+=i)
        	{
        		Count[i] += num[j];
			}
		}

        for(int i=1;i<=Maxx;i++){
        	ans += (mu[i] * 1LL * Count[i] * (Count[i] - 1)) >> 1;
		}
        printf("%lld\n",ans); 
	}
	return 0;
}