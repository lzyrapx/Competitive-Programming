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
	int m,n;
	while(cin>>m>>n)
	{
		if(m>=n)
			swap(m,n);
		long x=0,y=0;
		for(int i=m;i<=n;i++)
		{
		if(i%2==0)
	    x+=i*i;
		else
		y+=i*i*i;
	    }
	    cout<<x<<" "<<y<<endl;
	}
	return 0;

}

