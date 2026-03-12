#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,i,j,sum,num;
    while(~scanf("%d",&n))
    {
       num=0;
       for(i=1;i<n;i++)
        {
            sum=0;
            for(j=i;j<=n;j++)
            {
                sum+=j;
                if(sum>=n) break;                
            }
            if(sum==n) num++;  
         }
        printf("%d\n",num+1);         //加上本身                  
    }
    return 0;
} 