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
int prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
		if(i>n)return 1;
	}
}

int main()
{
    int m;
    while(cin>>m){
    	if(prime(m)){
    		printf("%d\n",m);continue;
    	}
    	
    	for(int i=2;i<=sqrt(m);i++){
    		if(m%i==0){
    			printf("%d*",i);
    			m/=i;
    			i=1;
    		}
    	}
    	printf("%d\n",m);
    	
    }
	
			
   return 0;
}

