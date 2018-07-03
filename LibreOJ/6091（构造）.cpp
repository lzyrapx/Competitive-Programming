#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000010;
const int mod = 1e9+7;
int a[1010],b[1010];
int d[1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int x,y;
	for(int i=1;i<=n;i++){
		if(d[i]==2){
			x = i ;
		}
		if(d[i]==0)
		{
			y = i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x)
		{
			a[i] = y;
			int tot = 0;
			for(int j=1;j<=n;j++){
				if(a[j]!=b[j]) tot++;
			}
			if(tot==1)
			{
				for(int j=1;j<=n;j++){
					printf("%d ",a[j]);
				}
				exit(0);
			}
			a[i] = x;
		}
	}
	return 0;
}