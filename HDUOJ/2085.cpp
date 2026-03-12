#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
		
	int n,i;
    long long int a,b,c;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {    
        a=1;b=0;
        for(i=0;i<n;i++)
        {
            c=a*3+b*2;
            b=a+b;
            a=c;
        }
        printf("%lld, %lld\n",a,b);
    }
   return 0;

} 