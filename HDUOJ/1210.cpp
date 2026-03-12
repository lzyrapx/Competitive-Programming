#include<stdio.h>
//数字1的下一位置 = 它的上一位置*2 %(总牌数+1)
int main()
{
    int n,t,sum;
    int pos;//记录1的位置 
    while(~scanf("%d",&n))
    {
        pos=1;//一开始1在第一个位置 
        t=2*n+1;
        sum=0; 
        while(1)
        {
            pos=pos*2%t;//1的下一个位置 
            sum++;
            if(pos==1)//1回到第一个位置 
            break;
        }
        printf("%d\n",sum);
    }
    return 0;
}