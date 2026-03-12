#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    while(cin >> n >> m)
	{
    	ll t1 = gcd(n, m);
    	ll t2 = 2 * n * m;
    	ll num = gcd(t1, t2);
    	ll p = t1 / num;
   	 	ll q = t2 / num;
    	cout << p <<"/" << q <<endl;
    }
    return 0;
}