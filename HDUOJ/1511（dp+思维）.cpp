#include<bits/stdc++.h> 
using namespace std;
char sa[123];
int dp[123];
bool isgreater(int i,int j,int m,int n) //判断从i~j的串是否大于从m~n的串  
{  
    while(sa[i]=='0'&&i<=j)//去掉前导0  
        i++;  
    while(sa[m]=='0'&&m<=n)//去掉前导0  
        m++;  
    if(i>j) //前者为0  
        return false;  
    if(m>n) //后者为0  
        return true;  
    int a=j-i+1,b=n-m+1;//数字的长度，即数字的位数  
    if(a>b)  
        return true;  
    else if(a<b)  
        return false;  
    else  
    {  
        for(int k=i,p=m; k<=j&&p<=n; k++,p++)//如果两个数字的位数相同，就逐位比较  
        {  
            if(sa[k]>sa[p])//前一个数字大于后一个  
                return true;  
            else if(sa[k]<sa[p])//后一个数字大于前一个  
                return false;  
        }  
    }  
    return false; //等于的情况  
}  
int main()  
{  
    while(~scanf("%s",sa+1))//字符串下标从1开始读入  
    {  
        int n=strlen(sa+1);//字符串总长  
        if(n==1&&sa[1]=='0') break;  
        dp[1]=1;//dp[i]表示从第i位往前共长度最小为dp[i]组成一个数字时的情况  
        for(int i=2; i<=n; i++)  //从前往后 dp 
        {  
            dp[i]=i;  
            for(int j=i-1; j>=1; j--)  
                if(isgreater(j+1,i,j-dp[j]+1,j))  
                {  
                    dp[i]=i-j; //求出满足题意的最小长度，即最后一个数尽可能的小  
                    break;//跳转到下一个 i  
                }  
        }
        
        //然后从后往前，dp[i]表示在满足第一个条件的情况下，从i开始的最大长度  
        int len=n-dp[n]+1;//len表示原字符串中去掉最后一个数的第一个字符的位置  
        dp[len]=dp[n];//最后一个数的长度  
        for(int i=len-1; i>=1; i--)  
        {  
            if(sa[i]=='0')//数有前导0  
            {  
                dp[i]=dp[i+1]+1;//该数字长度再加上前导0的长度  
                continue;  
            }  
            for(int j=len; j>i; j--)//求出长度最大的  
                if(isgreater(j,j+dp[j]-1,i,j-1))  
                {  
                    dp[i]=j-i;//使第一个数尽可能大  
                    break;  
                }  
        }  
        for(int i=1; i<=dp[1]; i++) //输出第一个数字  
            putchar(sa[i]);  
        int t=dp[1]+1;//第二个数字的起始位置  
        while(t<=n)  
        {  
            putchar(',');  
            for(int i=t; i<t+dp[t]; i++)  
                printf("%c",sa[i]);  
            t=t+dp[t];//转移到下一个数字的起始位置  
        }  
        putchar('\n');  
    }  
    return 0;  
}  