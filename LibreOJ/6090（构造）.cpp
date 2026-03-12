#include<bits/stdc++.h>
using namespace std;

int a[234],b[234];
bool flag;
int main()
{
	int n,k;
	flag = true;
	int pos;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0&&flag)
		{
			pos = i;
			flag =false;
		 } 
	}
	for(int i=0;i<k;i++)cin>>b[i];
	
	if(k==1)
	{
		a[pos]=b[0];		
		int ans = 1;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				cout<<"Yes"<<endl;
					
				ans = 0;
				break;
			} 
		}
		if(ans)cout<<"No"<<endl;
	}
	else
		cout<<"Yes"<<endl;
	
	return 0;
 } 