#include<stdio.h>
int main (void)
{
    int n, i;
    scanf("%d",&n);
    while (n--)                                       //要计算的行数
    {
        {
            int s;
            s = 0;
            scanf("%d",&i);
            while(i--)                       //要计算的数字个数
            {
                int a;
                scanf("%d",&a);
                s = s+a;                 //一次读取一个数字然后累加
            }
            printf("%d\n",s);
        }
    }
    return 0;
}