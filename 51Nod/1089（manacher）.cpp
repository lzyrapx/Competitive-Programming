//O(n) manacher算法 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1e6+5;
int l,len,p[N<<1];
char s[N],S[N<<1];
void manacher()
{
    int ans=0,id=0,mx=-1;
    for(int i=1;i<l;i++)
    {
        if(id+mx>i) p[i]=min(p[id*2-i],id+mx-i);
        while(i-p[i]-1>=0&&i+p[i]+1<=l&&S[i-p[i]-1]==S[i+p[i]+1]) p[i]++;
        if(id+mx<i+p[i])
        {
            id=i,mx=p[i];
        }
        ans=max(ans,p[i]);
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%s",s);
    len=strlen(s);
    l=-1;
    for(int i=0;i<len;i++) S[++l]='#',S[++l]=s[i];
    S[++l]='#';
    manacher();
    return 0;
}