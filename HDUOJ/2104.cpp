#include <stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()

{
    int n,m;
    while(scanf("%d%d",&n,&m),n!=-1&&m!=-1)
    {
         if(gcd(n,m)==1) puts("YES");
         else puts("POOR Haha");
    }
    return 0;
}//求n m是否互质