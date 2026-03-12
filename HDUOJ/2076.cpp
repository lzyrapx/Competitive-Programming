#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main() {
	int h,m,s;
	int t;
	double n1,n2,n3;
	int ans;
	cin>>t;
	while(t--)
	{
		cin>>h>>m>>s;
		n1=h/12.0+m/60.0/12.0+s/60.0/60.0/12.0;
        n2=m/60.0+s/60.0/60.0;
		n3=fabs(n1-n2)*360;
		 while(n3>=360.0){
		 	n3=n3-360.0;
		 }
		 while(n3>=180.0)
		 {
		 	n3=360.0-n3;
		 }
		 ans=n3;
		cout<<ans<<endl;		
	}
	return 0;
}