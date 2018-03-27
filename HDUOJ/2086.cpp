#include<stdio.h>
#include<iostream>
int main()
{
	   double c[3005]={0},a0,an1;
		int n;
        int i,j;
        while(~scanf("%d",&n))
        {
           scanf("%lf%lf",&a0,&an1);
           for(i=1;i<=n;i++)
            scanf("%lf",&c[i]);
            double sum=0;
            sum+=n*a0+an1;
            for(i=1;i<=n;i++)
            {
                sum-=2*(n-i+1)*c[i];
            }
            sum/=n+1;
            printf("%.2lf\n",sum);
        }
        return 0;
}