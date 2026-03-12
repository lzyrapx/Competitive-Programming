#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,T;
	double sum;
	cin>>T;
	while(T--){
		cin>>n;
		sum=0.0;
		for(i=2;i<=n;i++){
			sum+=log10(i);
		}
		cout<<(int)sum+1<<endl;
	}
	return 0;
}