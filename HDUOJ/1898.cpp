#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main() 
{
	int n;cin>>n;
    while(n--){
        int a,b,t; cin>>a>>b>>t;
        if(t%a==t%b)cout<<"Both!"<<endl;
        else if(t%a>t%b)cout<<"Xiangsanzi!"<<endl;
        else cout<<"Sempr!"<<endl;
    }

	return 0;
} 