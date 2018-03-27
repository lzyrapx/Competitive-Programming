#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
/*
int pow_mod(int a,int p)    //快速幂取模 
{
    if(p==0) return 1;
    int ans=pow_mod(a,p/2);
    ans=ans*ans%1000;
    if(p%2==1) ans=ans*a%1000;
    return ans;
}
*/
int pow_mod(LL a,LL b,int c){    //快速幂取模 
	LL ans=1;
	a=a%c;
	while(b>0){
		if(b&1){         //b&1相当于b%2==1
			ans=(ans*a)%c;
		}
		b=b>>1;  
        a=(a*a)%c;
	}
	return ans;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0&&b==0) break;
        printf("%d\n",pow_mod(a,b,1000));
    }
}
/*
#include<cstdio>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)   
    {
        if(a==0&&b==0) break;
        int ans=1;
        for(int i=0;i<b;i++)   //模拟 
            ans=ans*a%1000;
        printf("%d\n",ans);
    }
}
*/ 