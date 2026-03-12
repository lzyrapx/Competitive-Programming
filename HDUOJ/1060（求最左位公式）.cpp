#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,N;
	double x=0.0;
	cin>>t;
	while(t--){
		cin>>N;
		x=N*log10((double)N);
		x-=(long long)x;
		x=(int)pow(10,x);
		cout<<x<<endl;
	}
	return 0;
}