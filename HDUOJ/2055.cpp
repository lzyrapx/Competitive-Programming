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
	
	int n,y,res;
	char x;
	cin>>n;
	while(n--){
		cin>>x>>y;
		y=(x>96)?96-x+y:x-64+y; //A:65 a:97
		cout<<y<<endl;
	}
    return 0;
}