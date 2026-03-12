#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005]; 
int main()
{
	int n;
	while(cin>>n)
	{
		int flag = 1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++) scanf("%d",&a[i]);  
        for(int j=0;j<n;j++) scanf("%d",&b[j]);  
        int ans=0;  
        for(int i=0;i<n;i++)  ans^=a[i];  
        for(int j=0;j<n;j++)  ans^=b[j];  
        for(int i=0;i<n;i++)  a[i]^=ans;  
        sort(a,a+n);  
        sort(b,b+n);  
        for(int i=0;i<n;i++)
        {
        	if(a[i]!=b[i])
        	{
        		flag = 0;
			}
		}
		if(flag)cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}