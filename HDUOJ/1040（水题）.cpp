#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
	int n,m, a[2000];
	int i;
	while (~scanf_s("%d", &n))
	{

		while (n--)
		{
			scanf_s("%d", &m);
			for (i = 1; i <= m; i++)
			{
				scanf_s("%d", &a[i]);
			}
			sort(a + 1, a + m + 1);
			for (i = 1; i <= m; i++)
			{
				if (i == m)
				{
					printf("%d\n", a[i]);
				}
				else
				{
					printf("%d ", a[i]);
				}
			}
		}
	}
}
 
