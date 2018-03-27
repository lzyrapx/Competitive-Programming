#include<stdio.h>
bool judge(int x,int y,int k)
{
    if(k==0) return false;
    for(int i=1;i<=k;i++)
    {
        if((x%10)!=(y%10)) return false;
        x/=10;
        y/=10;
    }
    return true;
}
int main()
{
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k)!=EOF)
    {
        if(a==0&&b==0) break;
        if(judge(a,b,k)) printf("-1\n");
        else printf("%d\n",a+b);
    }
    return 0;
}