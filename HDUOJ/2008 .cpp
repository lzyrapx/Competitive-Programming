#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,i,a,b,c;
	double x;
	while(cin>>n){
		if(n==0)break;
		a=b=c=0;
		for(i=0;i<n;i++){
			cin>>x;
			if(x>0)c++;
			else if(x<0)a++;
			else b++;
		}
		printf("%d %d %d\n",a,b,c);
	}
     return 0;
}