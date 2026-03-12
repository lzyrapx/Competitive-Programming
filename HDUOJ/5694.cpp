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
using namespace std;
LL a[70];
LL calc(LL x)
{
    if(x==0) return 0;
    LL sum=0;
    for(int i=1;i<=60;i++)
    {
        if(a[i]==x)
            return x/2+1;
        if(x<a[i])
        {
            sum+=x-a[i-1];
            sum+=calc(a[i]-x);
            break;
        }
    }
    return sum;
}
int main()
{
    int T;
    long long L,R;
    scanf("%d",&T);
    a[0]=0;
    for(int i=1;i<=60;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    while(T--)
    {
        scanf("%I64d%I64d",&L,&R);
        printf("%I64d\n",calc(R)-calc(L-1));
    }
    return 0;
}