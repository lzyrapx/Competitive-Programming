/*
* this code is made by LzyRapx
* Problem: 1055
* Verdict: Accepted
* Submission Date: 2017-07-04 20:29:58
* Time: 248MS
* Memory: 5464KB
*/
#include <bits/stdc++.h>
using namespace std;
struct data
{
    int x,y;
    char ch;
}d[123456];
int tree[200010][2];
int has[200010],all;
int lowbit(int x)
{
    return x&(-x);
 
}
 
void update(int x,int val,int k)
{
    while(x<=all)
    {
        tree[x][k] += val;
        x+=lowbit(x);
    }
}
int query(int x,int k)
{
    int res = 0 ;
    while(x)
    {
        res += tree[x][k];
        x -= lowbit(x); 
    }
    return res;
}
int solve(int l,int r)
{
    return query(r,0) - query(l-1,1);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        all = 0;
        for(int i=1;i<=n;i++)
        {
            getchar();
            scanf("%c",&d[i].ch);
            if(d[i].ch=='C')
            {
                scanf("%d",&d[i].x);
                has[all++] = d[i].x;
            }
            else // D , Q 
            {
                scanf("%d%d",&d[i].x,&d[i].y);
                has[all++] = d[i].x;
                has[all++] = d[i].y;
            }
        }
        sort(has,has+all);
        all = unique(has,has+all) - has;
        memset(tree,0,sizeof(tree));
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(d[i].ch =='D')//draw 
            {
                int l = lower_bound(has, has+all, d[i].x) - has;
                int r = lower_bound(has, has+all, d[i].y) - has;
                update(l+1,1,0);
                update(r+1,1,1);
                d[++cnt] = d[i];
            }
            else if(d[i].ch == 'Q') //query 
            {
                int l = lower_bound(has,has+all,d[i].x) - has;
                int r = lower_bound(has,has+all,d[i].y) - has;
                printf("%d\n",solve(l+1,r+1));
            }
            else if(d[i].ch == 'C') //clear 
            {
                int l = lower_bound(has,has+all,d[d[i].x].x) - has;
                int r = lower_bound(has,has+all,d[d[i].x].y) - has;
                update(l+1,-1,0);
                update(r+1,-1,1);
            }
        }
    }
    return 0;
}