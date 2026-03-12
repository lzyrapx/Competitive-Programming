#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main()
{
	int t;
	LL a,b,c,temp;
	cin>>t;
   while(t--)
   {
   	  LL ans=0;
   	  cin>>a>>b>>c;
   	   temp=a;
   	  for(int i=1;i<b;i++)
   	  {
   	  	   a=a*temp;
   	  	   a=a%c;
   	  }
   	  ans=a%c;
   	  printf("%lld\n",ans);
   }
    return 0;
}


#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;

int q_mod(LL a,LL b,LL c)
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
	int t;
	
	LL a,b,c;
	cin>>t;
   while(t--)
   {  	  
   	  cin>>a>>b>>c; 	  
   	  printf("%d\n", q_mod(a,b,c));  //注意这里不能为lld 
   }
    return 0;
}