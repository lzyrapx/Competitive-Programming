#include<bits/stdc++.h>
using namespace std;
bool vis[123456];
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		if(n<0){ //注意：可以是负数
			printf("-");
			n=-n;
		}
		if(n==1){
			puts("1");
			continue;	
		}
		memset(vis,false,sizeof vis);
		printf("0.");
		vis[0] = true;
		int m = 1;
		while(vis[m]==false)
		{
			vis[m] =  true;
			m *= 10;
			printf("%d",m/n);
			m%=n;
		}
		cout<<endl;
	}
	return 0;
 } 