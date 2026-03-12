#include<stdio.h>
int a[100][100];
int main()
{
    int t,n,m,sum,i,j;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    scanf("%d",&a[i][j]);
                    if(a[i][j]==1)
                        sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}