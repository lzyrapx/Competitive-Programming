#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long mod=110119;
LL all[mod+10],f[mod+10];

LL dp[2010];
struct node
{
    LL x,y;
} point[2010];
LL cmp(node a,node b)
{
    return a.x<b.x;
}
void init()
{
    f[1]=f[0]=all[1]=1;
    for(int i=2; i<=mod; ++i)
    {
        f[i]=f[i-1]*i%mod;
        all[i]=all[mod%i]*(mod-mod/i)%mod;
    }
}
LL C(LL n, LL m)
{
    if(m > n) return 0;
    if (m==0) return 1;
    if (m<0) return 0;
    return f[n]*all[f[m]]%mod*all[f[n-m]]%mod;
}
LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}


int main()
{
    init();
    LL h,w,n,cas=1;
    while (scanf ("%lld%lld%lld",&h,&w,&n)!=EOF)
    {
        int flag=0;
        memset(dp,0,sizeof(dp));
        LL t1,t2;
        for (int i=0; i<n; ++i)
        {
            scanf ("%lld%lld",&t1,&t2);
            if (t1==h&&t2==w) flag=1;
            point[i].x=t1-1;
            point[i].y=t2-1;
        }
        sort(point,point+n,cmp);
        point[n].x=h-1;
        point[n].y=w-1;
        ++n;
        if ((point[n-1].x+point[n-1].y)%3!=0||flag)
        {
        	//printf("n=%lld\n",n);
        	//printf("dp[0]=%lld\n",dp[0]);
            printf ("Case #%lld: %d\n",cas++, 0);
            continue;
        }
        for (int i=0; i<n; i++)
        {
            if ((point[i].x+point[i].y)%3==0)
            {
                LL low=(point[i].x+point[i].y)/3;
                LL high=min(point[i].x,point[i].y)-low;
                dp[i]=Lucas(low,high);

                for (int j=0;j<i;j++)
                {
                    if (point[j].y<point[i].y&&point[j].x<point[i].x)
                    {
                        LL xx=point[i].x-point[j].x,yy=point[i].y-point[j].y;
                        if ((xx+yy)%3==0)
                        {
                            LL dd=(xx+yy)/3;
                            LL gg=min(xx,yy)-dd;
                            dp[i]-=(Lucas(dd,gg)*dp[j])%mod;
                            dp[i]=(dp[i]+mod)%mod;
                        }
                    }
                }
            }
        }
        //printf("n=%lld\n",n);
        //printf("dp[0]=%lld\n",dp[0]);
        printf ("Case #%lld: %lld\n",cas++,dp[n-1]);
    }
    return 0;
}

