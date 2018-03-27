#include<bits/stdc++.h>
using namespace std;
map <string ,int> m;
int main()
{
	m["one"]=1;
	m["two"]=2;
	m["three"]=3;
	m["four"]=4;
	m["five"]=5;
	m["six"]=6;
	m["seven"]=7;
	m["eight"]=8;
	m["nine"]=9;
	m["zero"]=0;
	string a;
	int tmp;
	while(1)
	{
		int x=0;
		while(cin>>a,a!="+")
		{
			x=x*10+m[a];
		}	
		int y=0;
		while(cin>>a,a!="=")
		{
			y=y*10+m[a];
		}	
		if(x==0&&y==0)
		break;
		printf("%d\n",x+y);		
	}
	return 0;
}