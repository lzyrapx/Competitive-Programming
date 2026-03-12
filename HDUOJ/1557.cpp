#include <stdio.h>
#include <string.h>
int ans[25];
int a[25];

int main()
{
    int i,j,n,s,sum,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        memset(ans,0,sizeof(ans));
        for (i=0;i<(1<<n);i++)
        {
            s=0;
            for (j=0;j<n;j++)
            {
                if ((i & (1<<j))!=0) s+=a[j];//该团体的总票 
            }
            
            if (2*s<=sum) continue;
            
            for (j=0;j<n;j++)
            {
                if ((i & (1<<j))!=0) //每个成员 
                {
                    if (2*(s-a[j])<=sum) ans[j]++;
                }
            }
        }
        for (i=0;i<n-1;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[i]);
    }
    return 0;
}
