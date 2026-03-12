#include<iostream>   
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
#include<queue>
#include<algorithm>  
typedef long long LL;  
using namespace std; 

int main()
{
    int t,b;
    char a[500];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%d",a,&b);
        int k=-1;
        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]=='.')
            {
                k=i;break;
            }
        }
        if(b>strlen(a)-k-1)
        {
            puts("0");continue;
        }
        printf("%c\n",a[k+b]);
    }
    return 0;
}