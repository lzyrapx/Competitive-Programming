#include<bits/stdc++.h>
using namespace std;
int a[1000001]={0};
int main()
{
	int i,j,sum=0;
    for(i=1;i<=1000000;i++)
    {
        j=i;
        for(sum=j;j;j/=10)
            sum+=j%10;
        a[sum]=1;
        if(!a[i])
            printf("%d\n",i);    
    }
    return 0;
}