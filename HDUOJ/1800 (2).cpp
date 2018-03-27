#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,f[3000+5];
int main()
{
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)scanf("%d",&f[i]);
        sort(f,f+n);
        int max=1,count=1;
        for(i=1;i<n;i++)
        {
            if(f[i]>f[i-1])count=1;
            else { count++; max = max>count? max:count;}
        }
        printf("%d\n",max);
    }
    return 0;
}