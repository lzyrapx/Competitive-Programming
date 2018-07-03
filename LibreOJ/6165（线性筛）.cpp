#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e8+7;
int n;
ll prime[6000005];
bool vis[100000005];
ll cnt;
void Sieve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
int main()
{
	scanf("%d", &n);
	Sieve(n);
	ll x, y;
	ll ans = 1;
	for (int i = 1; i <= cnt; i++)
	{
		x = prime[i];
	//	cout<<"x="<<x<<endl; 
		while ((y= x * prime[i])<= n)
		{
			x = y;
		//	cout<<"y="<<y<<endl;
		}
	//	cout<<"xx="<<x<<endl;
		ans = ans * x % 100000007;
	}
	printf("%lld", ans);
	return 0;
}