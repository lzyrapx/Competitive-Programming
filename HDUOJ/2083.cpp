#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int k,m,n,i,a[10005];
    int s;
    scanf("%d",&m);
    while(m--)
    {
        s=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        k=n/2;
        for(i=0;i<n;i++)
            s+=abs(a[i]-a[k]);
        printf("%d\n",s);
    }
}