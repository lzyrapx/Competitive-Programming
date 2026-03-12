#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 //0.618033988749894848204586834... 拆成整数放进数组里，
 //拆成三部分即可 
 //http://blog.csdn.net/liangzhaoyang1/article/details/72594221 
ll tmp[3] = {618033988,749894848,204586834};
ll MOD = 1e9;

int main()
{
	int t;	
	scanf("%d",&t);
	while(t --)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);		
		if(a > b)
		{
			ll t = a;
			a = b;
			b = t;
		}
		ll diff = b - a;
		//把10^18分成两部分10^9
		ll ta = diff / MOD; 
		ll tb = diff % MOD;
		
		ll tp = tb * tmp[2];
		tp = ta * tmp[2] + tb * tmp[1] + tp / MOD;
		tp = ta * tmp[1] + tb * tmp[0] + tp / MOD;
		tp = ta * tmp[0] + tp / MOD + diff; 
		
		if(tp == a)
			printf("B\n");
		else
			printf("A\n");
	}
	return 0;
}