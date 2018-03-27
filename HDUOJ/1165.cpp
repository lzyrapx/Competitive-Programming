/*
推导公式：m=0时 A(m,n)=n+1;
m=1时 A(m,n)=A(0,A(1,n-1))=A(1,n-1)+1=A(1,n-2)+1+1=……=n+2;
m=2时 A(m,n)=A(m,n-1)+2 =2*n+3
m=3时 A(m,n)=A(2,A(m,n-1))=A(m,n-1)*2+3
*/

#include<bits/stdc++.h>
using namespace std;
long long A(long long m,long long n)
{
	if(n==0) return A(m-1,1);
	else if(m==0)return n+1;
	else if(m==1) return n+2;
	else if(m==2) return A(m,n-1)+2;
	else  if(m==3)return A(m,n-1)*2+3;
}
int main()
{
	long long n,m;
	while(~scanf("%lld%lld",&m,&n))
		printf("%lld\n",A(m,n));
    return 0;
}