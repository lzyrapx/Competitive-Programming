#include <bits/stdc++.h>
using namespace std;
const int N=1234;

bool check(int n)
{
	if(n<=1)return false;
	if(n<=3)return true;
	if(n%2==0)return false;
	for(int i=3;i*i<=n;i++)
	{
		if(n%i==0)return false;	
	}
	return true;
}
int main()
{  
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	if(check(n)){
    		puts("Yes");
		}
		else puts("No");
	}
    return 0;
}