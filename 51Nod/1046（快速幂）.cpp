#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int q_mod(LL a,LL b,LL c) //a^c mod c
{  
    LL ans=1;  
  
    while(b>0){  
        if(b&1)  
        ans=(ans*a)%c;  
          
        b>>=1;  
        a=(a*a)%c;  
    }  
    return ans;  
}  
int main()
{
	LL a,b,p;
	cin>>a>>b>>p;
	cout<<q_mod(a,b,p)<<endl;
	return 0;
}