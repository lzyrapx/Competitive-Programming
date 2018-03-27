#include<stdio.h>
int main()
{
    int n,i,s;
    while(scanf("%d",&n)!=EOF)
    {
        s=0;
        while(n--)
        {
            scanf("%d",&i);
            s=s+i;
        }
        printf("%d\n",s);
    }
    return 0;
}