#include <cstdio>
int main()
{
    int i,j,x,n,m,sum,max;
    int start,end,nowstart;
    scanf("%d",&n);
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&m,&x);
            sum=max=x;
            start=end=nowstart=1;
            for (j=2;j<=m;j++)
            {
                scanf("%d",&x);
                if (sum+x<x)
                {
                    sum=x;
                    nowstart=j;
                }
                else
                {
                    sum+=x;
                }
                if (sum>max)
                {
                    max=sum;
                    start=nowstart;
                    end=j;
                }
            }
            printf("Case %d:\n%d %d %d\n",i,max,start,end);
            if (i!=n)
            {
                printf("\n");
            }
        }
    }
    return 0;
}

