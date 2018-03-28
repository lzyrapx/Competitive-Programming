/*
* this code is made by LzyRapx
* Problem: 1056
* Verdict: Accepted
* Submission Date: 2017-06-06 23:08:08
* Time: 36MS
* Memory: 1684KB
*/
#include <bits/stdc++.h>
using namespace std;
map<string,int>color;
int fa[456];
int getfather(int x)
{
    return fa[x]==x?x:fa[x]=getfather(fa[x]);
}
 
void Merge(int a,int b)
{
    int p1=getfather(a);
    int p2=getfather(b);
    fa[p1] = p2;
}
int main()
{
    int cas=1,t;
    cin>>t;
    int n;
    string s1,s2;
    while(t--)
    {
        int flag = 1;
        color.clear();
        int t = 1;
        cin>>n;
        n<<=1;
        for(int i=1;i<=n;i++)fa[i]=i;
        n>>=1;
        for(int i=1;i<=n;i++)
        {
            cin>>s1>>s2;
            if(flag==0)continue;
            if(color[s1]==0) color[s1] = t++;
            if(color[s2]==0) color[s2] = t++;
            if(getfather(color[s1]) != getfather(color[s2]) )
            {
                Merge(color[s1],n+color[s2]);
                Merge(color[s1]+n,color[s2]);
            }
            else
            {
                flag = 0;
            }
        }
        printf("Case #%d: ",cas++);
        puts(flag?"Yes":"No");
    }
    return 0;
}