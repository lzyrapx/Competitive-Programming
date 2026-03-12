#include<stdio.h>
int main()
{
    int T,n,a,sum=0,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
        sum=0;
        if(T!=0)
            printf("\n");
    }
}