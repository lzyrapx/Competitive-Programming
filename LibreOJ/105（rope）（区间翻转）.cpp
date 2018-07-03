#include<bits/stdc++.h>
#include<ext/rope> 
using namespace std;
using namespace __gnu_cxx;
rope<int>rop,rp;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		rop.push_back(n-i+1);
		rp.push_back(i);
	}
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		rope<int> tmp = rp.substr(l-1,r-l+1);
		rope<int> temp = rop.substr(n-r,r-l+1);
		rp=rp.substr(0,l-1) + temp + rp.substr(r,n-r);
		rop = rop.substr(0,n-r) + tmp + rop.substr(n-l+1,l-1); 
	}
	char c;
	for(int i=0;i<n;i++){
		printf("%d%c",rp[i],(c=i)==n-1?'\n':' ');
	}
	return 0;
}