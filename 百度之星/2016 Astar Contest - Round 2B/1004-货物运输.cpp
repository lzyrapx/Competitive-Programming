#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=1000005;

int L[N],R[N],n,m;

inline bool check(int k)
{
    int l=2,r=n+n;
    for(int i=1;i<=n&&l<=r;i++)
        if(R[i]-L[i]>k)
        {
            l=max(l,L[i]+R[i]-k);
            r=min(r,L[i]+R[i]+k);
        }
    if(l>r)
        return 0;
    l=1-n,r=n-1;
    for(int i=1;i<=n&&l<=r;i++)
        if(R[i]-L[i]>k)
        {
            l=max(l,L[i]-R[i]-k);
            r=min(r,L[i]-R[i]+k);
        }
    if(l>r)
        return 0;
    return 1;
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&L[i],&R[i]);
            if(L[i]>R[i])
                swap(L[i],R[i]);
        }
        int l=0,r=n,Ans=n;
        while(l<=r)
        {
            int Mid=l+r>>1;
            if(check(Mid))
                Ans=Mid,r=Mid-1;
            else
                l=Mid+1;
        }
        printf("%d\n",Ans);
    }
    return 0;
}