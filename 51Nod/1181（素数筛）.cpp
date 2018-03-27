#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+1000;
int prime[maxn],num[maxn],k;

void init(int n)
{
	n=n+1000;
	int i,j;
	prime[0]=prime[1]=1; 
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			for(j=2*i;j<=n;j+=i)
			   prime[j]=1;   //不是素数 
		}
	}
	j=0,k=0;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])//是素数
		{    
			j++;
			if(prime[j]==0) num[k++]=i; 
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);  
	int n;
	cin>>n;
	init(n);
	cout<<*lower_bound(num,num+k,n)<<endl;
	return 0;
}
