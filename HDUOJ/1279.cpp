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

int main(){
	int n,m,i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		k=0;
		scanf("%d",&m);
	    while(m!=1)
	    {
    		if(m%2==0)
    		m=m/2;
    		else
    		{
    			k=k+1;
    			if(k==1)
		    	printf("%d",m);
		    	else
		    	printf(" %d",m);
		    	m=3*m+1;
		    }
    	}
    	if(k==0) printf("No number can be output !");
		printf("\n");
	}
	return 0;	

  return 0;
}