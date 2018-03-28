//其实就是每层图形从1一直相加，然后两层相乘就行了。
#include<iostream>
using namespace std;
int main()
{
	int t,sum1,sum2,i,n,m;
	while(cin >> t )
	{
		while(t --)
		{
			cin >> n >> m;
			sum1 = sum2 = 0;
			for( i = 1 ; i <= n ; i ++)
			{
				sum1 += i;			
			}
			for(i = 1 ; i <= m ; i ++)
			{
				sum2 += i;
			}
			cout << sum1 * sum2 << endl;
		}
	}
	return 0;
}

-----------------------------------
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
long long sum;
int main()
{
    int m,n,t;
    int i,j,i1,j1;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&m,&n);
        for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            for(i1=0;i1+i<=m;i1++)
            {
                for(j1=0;j1+j<=n;j1++)
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}