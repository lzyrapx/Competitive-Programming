/*
* this code is made by LzyRapx
* Problem: 1019
* Verdict: Accepted
* Submission Date: 2017-06-22 15:11:30
* Time: 1252MS
* Memory: 26084KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000010;
char s[maxn];
ll C[2][maxn];
ll Hash[maxn];
int seed=13;
int lowbit(int x)
{
    return x&(-x);
}
void init()
{
    Hash[0]=1;
    for(int i=1; i<maxn; i++)
        Hash[i]=Hash[i-1]*seed;
}
int len;
void update(int i,int pos,ll data)
{
    while(pos<=len)
    {
        C[i][pos]+=data;
        pos+=lowbit(pos);
    }
}
ll get(int i,int pos)
{
    ll ans=0;
    while(pos)
    {
        ans+=C[i][pos];
        pos-=lowbit(pos);
    }
    return ans;
}
ll gethash(int i,int l,int r)
{
    return get(i,r)-get(i,l-1);
}
int main()
{
    init();
    while(~scanf("%s",s+1))
    {
        memset(C,0,sizeof C);
        int t;
        cin>>t;
        len=strlen(s+1);
        //树状数组维护前缀和，维护两个串，一个正串，一个反串，用于比较
        for(int i=1; i<=len; i++)
        {
            update(0,i,(s[i] - 'a') * Hash[i]); //正串 
            update(1,len+1-i,(s[i] - 'a') * Hash[len+1-i]);//反串 
        }
        while(t--)
        {
            char c;
            getchar();
            scanf("%c",&c);
            if(c=='C') //change
            {
                char b[5];
                int a;
                scanf("%d%s",&a,b);  //change the ith letter to y.
                //正串 
                update(0,a,-(s[a] - 'a') * Hash[a]);
                update(0,a,(b[0] - 'a') * Hash[a]);
                //反串 
                update(1,len+1-a, -(s[a] - 'a') * Hash[len+1-a]);
                update(1,len+1-a, (b[0] - 'a') * Hash[len+1-a]);
                s[a]=b[0];
            }
            else //check palindrome 
            {
                int l,r;
                scanf("%d%d",&l,&r); // check ith letter to jth letter is a palindrome 
                if(gethash(0,l,r) * Hash[len-l] == gethash(1,len+1-r,len+1-l) * Hash[r-1])
                    puts("yes");
                else
                    puts("no");
            }
        }
    }
    return 0;
}