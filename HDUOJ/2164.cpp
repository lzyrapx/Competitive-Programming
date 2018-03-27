#include<iostream>   
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=100;

int main()
{
	int t,n,a,b;
	char ca,cb;
	cin>>t;
	while(t--)
	{
		a=b=0;
		cin>>n;
		while(n--)
		{
			cin>>ca>>cb;
			if(ca==cb)continue;
			else if(ca=='R'&&cb=='S'||ca=='S'&&cb=='P'||ca=='P'&&cb=='R')
			a++;
			else b++;
		}
		if(a==b)cout<<"TIE"<<endl;
		else if(a>b)
            cout<<"Player 1"<<endl;
        else
            cout<<"Player 2"<<endl;
  }
   return 0;
}