#include<iostream>
#include<memory.h>
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
//数学公式：1^3+2^3+3^3+....n^3=[n(n+1)/2]^2 
struct node
{
    char name[10];
    int m,s;
}p[11];
bool cmp(node a,node b)
{
    if(a.m==b.m&&a.s==b.s)
    return strcmp(a.name,b.name)<0; //按字典序从小到大 
    else if(a.m==b.m)
    return a.s<b.s; //从小到大 
    return a.m<b.m;
}
int main()
{
    bool ok=0;
    int i,j,n,ca=1,r,sum;
    while(~scanf("%d",&n),n)
    {
        if(ok)
        printf("\n");
        ok=1;
        for(i=0;i<n;i++)
        {
            scanf("%s %d:%d",p[i].name,&p[i].m,&p[i].s);
        }
        r=1,sum=1;
        sort(p,p+n,cmp);
        printf("Case #%d\n",ca++);
        for(i=0;i<n;i++)
        {
            if(i!=0&&(p[i].m!=p[i-1].m||p[i].s!=p[i-1].s))
            r=sum;   //r为名次 
            printf("%s %d\n",p[i].name,r);
            sum++;
        }
    }
    return 0;
}