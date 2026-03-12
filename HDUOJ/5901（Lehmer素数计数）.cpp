//1010 by Walker

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 10000000;

ll N;
bool isp[MAXN];
int pcnt[MAXN];
vector<int> primes;
void init()
{
  	for(int i=2; i<MAXN; i++){
  		isp[i] = true;
  	}
    
  	for(int i=2; i<MAXN; i++)
 	{	
    	if(!isp[i]) continue;
    	primes.push_back(i);
    	for(int j=2*i; j<MAXN; j+=i){
    		isp[j] = false;
		}
       	
  	}
   pcnt[0] = 0;
   for(int i=1; i<MAXN; i++){
   	  pcnt[i] = pcnt[i-1] + isp[i];
   }
     
}
ll prime_count(ll lim);

ll phi(ll m, int n)
{
  	if(m <= 0) return 0;
  	if(n == 0) return m;
  	if(primes[n-1] * primes[n-1] >= m) return prime_count(m) - n + 1;
  	return phi(m, n-1) - phi(m / primes[n-1], n-1);
}

ll prime_count(ll lim)
{
  	if(lim < MAXN) return pcnt[lim];
  
  	ll m3 = 1, m2 = 1;
 	while(m3*m3*m3<=lim) m3++;
 	while(m2*m2<=lim) m2++;
  	m3--;
  	m2--;

  	ll y = m3;
  	ll n = prime_count(y);
  	ll p2 = 0;
  	for(ll p=y+1; p<=m2; p++)
	  {
  		if(isp[p]){
  			p2 += prime_count(lim / p) - prime_count(p) + 1;
		  }
      
	}
  	ll ph = phi(lim, n);
  	ll res = ph + n - 1 - p2;
  	//cout<<lim<<" y "<<y<<" n "<<n<<" p2 "<<p2<<" phi "<<ph<<endl;
  	return res;
}
int main()
{
  	init();
  	while(~scanf("%I64d",&N))
  	{
  		ll ans = prime_count(N);
  		printf("%I64d\n",ans);
  }
  return 0;
}