#include <stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int n;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x,y,i;
        char a[10] = "#ZJUTACM";
        for(i = 0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            swap(a[x],a[y]);
        }
        for(i = 1;i<=7;i++)
        {
            if(a[i] == 'J')
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}