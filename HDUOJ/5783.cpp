#include<bits/stdc++.h>
long long a[1000010];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	long long sum=0;
        long long num=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        for(int i=n;i>=1;--i)
        {

            if(a[i]>=0)
            {
			    sum++; //子序列长度 
                a[i]=0;
            }
            else
            {
                num=a[i];
                a[i-1]+=num;

            }
        }
        printf("%I64d\n",sum);
    }
    return 0; 
}
