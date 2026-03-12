/*
* this code is made by LzyRapx
* Problem: 1070
* Verdict: Accepted
* Submission Date: 2017-07-09 13:15:09
* Time: 2508MS
* Memory: 8264KB
*/
#include<bits/stdc++.h>
using namespace std;
const int N=123456;
int n,q;
vector<int>p[N];
int solve(int l,int r,int k)
{
    return upper_bound(p[k].begin(),p[k].end(),r) - lower_bound(p[k].begin(),p[k].end(),l);
} 
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<N;i++){
            p[i].clear();
        }
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            p[x].push_back(i);
        }
        scanf("%d",&q);
        int l,r,w;
        for(int i=0;i<q;i++)
        {
            scanf("%d %d %d",&l,&r,&w);
            int sum = 0;
            for(int j=1;j*j<=w;j++)
            {
                if(w%j==0)
                {
                    sum+=solve(l,r,j);
                    if(j*j!=w)
                    {
                        sum+=solve(l,r,w/j);
                    }
                }
            }
            printf("%d\n",sum);
        }
     } 
    return 0;
}
