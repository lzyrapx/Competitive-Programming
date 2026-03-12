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

typedef long long LL; 

const int N=100005;

int a[N],n,m,k;
LL s[N],Ans;
vector<int> I[N];
multiset<int> S;

int main()
{
    while(cin>>n>>k>>m)
    {
        Ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s[i]=s[i-1]+a[i],I[i].clear();
        for(int i=1,l,r;i<=m;i++)
            scanf("%d%d",&l,&r),I[l].push_back(r);
        S.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<I[i].size();j++)
                S.insert(I[i][j]);
            while(S.size()>k)
                S.erase(S.begin());
            if(S.size()==k&&*S.begin()>=i)
                Ans=max(Ans,s[*S.begin()]-s[i-1]);
        }
        printf("%I64d\n",Ans);
    }
    return 0;
}
Close
