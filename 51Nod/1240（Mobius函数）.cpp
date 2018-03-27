#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Mobius(ll n)
{  
    ll m = 1;
    for(ll i = 2; i * i <= n; i++)
	{
        if(n % i == 0)
		{
            m *= -1;
            ll k = 0;
            do
			{
                k++;
                if(k > 1) { m = 0; break;}
                n /= i;
            }while ( n % i == 0);
        }
    }
    if(n > 1) m *= -1;
    return m;
}

int main()
{
    ll n;
    while(cin >> n)
	{
        cout<<Mobius(n)<<endl;
    }
}