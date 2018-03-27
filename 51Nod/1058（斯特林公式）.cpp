#include<bits/stdc++.h>
using namespace std;
const double Pi=3.1415926;
//斯特林公式:n!=sqrt(2*PI*n)*(n/e)^n
int main()
{
	int n;
	cin>>n;
	cout<<(int)((0.5*log(2*Pi*n)+n*log(n)-n)/log(10))+1<<endl;
	
	return 0;
}