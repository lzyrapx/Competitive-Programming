#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	int n,w,d,s,cha,yuan,ans;
    while(cin>>n>>w>>d>>s)
    {
        yuan=w*n*(n-1)/2;
        cha=yuan-s;
        ans=cha/d;
        if(ans==0)   //其实就是差(cha)等于0 
            cout<<n<<endl;
        else
            cout<<ans<<endl;
    }
	return 0;

}

