#include <iostream>
#include<stdio.h>
using namespace std;
#include<cmath>
//因为n=i*j+i+j+1-1=(i+1)(j+1)-1;
//n+1=(i+1)(j+1); 
//所以sqrt(n+1)>=(i+1) 
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    int t;
    cin>>t;
    while(t--)
    {

    	cin>>n;
    	int num;
    	int sum=0;
    	num=sqrt(n+1);
    	for(int i=1;i<num;i++)
    	{
    		if((n+1)%(i+1)==0)  //所以(j+1)为整数 
    		sum++;
		}
	cout<<sum<<endl;
	}
    return 0;
}

