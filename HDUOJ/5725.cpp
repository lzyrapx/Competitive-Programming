#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int d[25],f[1050000];
int get(int x) {
    int i,bo=0,w;
    for (i=1;i<=20;i++)
    if ((1<<i)-1==x) return 0;
    memset(d,0,sizeof(d));
    for (i=0;i<20;i++)
    if ((1<<i)>x) break ;
    else if (((1<<i)&x)==0) { bo=1;w=i; }
        else if (bo) {
            d[f[x-(1<<i)+(1<<w)]]=1;
        }
    for (i=0;i<25;i++)
    if (!d[i]) return i;
}
int main()
{
    int i,j,g,x,n,t,sum,ans;
    f[0]=0;
	for(i=1;i<=(1<<20);i++) f[i]=get(i);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);ans=0;
        for (i=1;i<=n;i++) {
            scanf("%d", &g);sum=0;
            for (j=1;j<=g;j++) {
                scanf("%d", &x);sum+=1<<(20-x);
            }
            ans^=f[sum];
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}