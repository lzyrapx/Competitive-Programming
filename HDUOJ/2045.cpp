#include<iostream>
using namespace std;
long long a[55];
int main()
{
	long long n;
	a[0]=0;
	a[1]=3,a[2]=6,a[3]=6;
	for(int i=4;i<=55;i++){
		a[i]=a[i-1]+2*a[i-2];
	}
    while(cin>>n)
    {
    	cout<<a[n]<<endl;
	}
	return 0;
}