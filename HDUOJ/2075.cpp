#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		long a,b;
		cin>>a>>b;
		if(a%b==0)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}