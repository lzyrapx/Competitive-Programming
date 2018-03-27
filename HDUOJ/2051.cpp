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
	
	int i,n,m,j,a[100]={0};
    while(scanf("%d",&n)!=EOF)
    {
        i=0;
        while(n)
        {
            a[i]=n%2;
            i++;
            n/=2;
        }
        
        for(int j=i-1;j>=0;j--)
            printf("%d",a[j]);
        printf("\n");
    }
    return 0;
}