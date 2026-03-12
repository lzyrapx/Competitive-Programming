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

int main()
{
	int n;
	cin>>n;
	getchar(); 
	while(n--){
		int a,b,c,x,y,z;
		cin>>a>>b>>c>>x>>y>>z;
		if(c+z>=60){
			c=c+z-60;
			b=b+1;
		}
		else
		c=c+z;
		if(b+y>=60){
			b=b+y-60;
			a=a+1;
		}
		else
		b=b+y;
		a=a+x;
		cout<<a<<" "<<b<<" "<<c<<endl;
	} 
    return 0;
}