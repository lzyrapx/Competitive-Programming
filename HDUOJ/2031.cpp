#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
    int n,m,i,x,flag;
    int a[1000];
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        flag=0;
        if (n<0)
        {
            n=-n;
            flag=1;
        }
        x=0;
        while (n>0)  //模拟 
        {
            a[x]=n%m;
            n/=m;
            x++;
        }
        while (x--)
        {
            if (flag)
            {
                printf("-");
                flag=0;
            }
            if (a[x]<10)
                printf("%d",a[x]);
            else printf("%c",55+a[x]);  //int 与 char类型的转换精髓 
        }
        printf("\n");
    }
    return 0;
}