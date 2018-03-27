#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	int step,mod;
	while(~scanf("%d%d",&step,&mod)){
		int ans=gcd(step,mod);
		if(ans==1) printf("%10d%10d    Good Choice\n\n",step,mod);
        else printf("%10d%10d    Bad Choice\n\n",step,mod);
	} 
        
	return 0;
}