#include<iostream>  
#include<memory.h>  
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const LL maxn=1e6;
const LL mod=10000000; 
//输入一个字符串，再输入旋转次数,每次转动45度，注意number可以是负数 
char str[80 + 5];
int main()
{
    int number;
    while(scanf("%s%d", str, &number) != EOF)
    {
        int len = strlen(str);
        if(number % 8 == 0)
        {
            for(int i = 0; i < len; i++)
                printf("%c", str[i]);
            printf("\n");
        }
        else if(number % 8 == 1 || number % 8 == -7)
        {
            for(int i = len - 1; i >= 0; i--)
            {
                for(int j = 0; j < i; j++)
                printf(" ");
                printf("%c\n", str[i]);

            }
        }
        else if(number % 8 == 2 || number % 8 == -6)
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < len / 2; j++)
                    printf(" ");
                printf("%c\n", str[len - 1 - i]);
            }
        }
        else if(number % 8 == 3 || number % 8 == -5)
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < i; j++)
                printf(" ");
                printf("%c\n", str[len - 1 - i]);

            }
        }
        else if(number % 8 == 4 || number % 8 == -4)
        {
            for(int i = len - 1; i >= 0; i--)
                printf("%c", str[i]);
            printf("\n");
        }
        else if(number % 8 == 5 || number % 8 == -3)
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < len - i - 1; j++)
                    printf(" ");
                printf("%c\n", str[i]);
            }
        }
        else if(number % 8 == 6 || number % 8 == -2)
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < len / 2; j++)
                    printf(" ");
                printf("%c\n", str[i]);
            }
        }
        else if(number % 8 == 7 || number % 8 == -1)
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < i; j++)
                printf(" ");
                printf("%c\n", str[i]);

            }
        }
    }
    return 0;
}
