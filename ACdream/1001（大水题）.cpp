#include <bits/stdc++.h>
using namespace std;
void SwapInt(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	int a = 3,b = 5;
	SwapInt(&a,&b);	
	cout<<a<<" "<<b<<endl;
	return 0;
}