#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n,n)
    {
    	int res=n*(n+1)/2;
    	if(res%2==0)puts("Y");
    	else puts("N");
	}
    return 0;
}

