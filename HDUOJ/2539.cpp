#include<iostream>   
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<queue>
#include<algorithm>  
typedef long long LL;  
using namespace std; 
int a[50];
int main()
{
	int n;
	while(cin>>n,n)
	{
		getchar();
		int t=(n+1)/2;
		memset(a,-1,sizeof(a));
		for(int i=0;i<n;i++)
		{
			string s;
			getline(cin,s);
			int len=s.size();
			if(s.find(" no good")==len-8) a[i]=0;
			else a[i]=1;
		}
		for(int i=1;i<=t;i++)
		cout<<i<<' ';
		cout<<"Score"<<endl;
		int q=0;
		for(int i=0;i<n;i+=2){
			if(a[i]==1) cout<<'O'<<' ', q++;
		else cout<<'X'<<' '; 
		}
		cout<<q<<endl;
		q=0;
		for(int i=1;i<t*2;i+=2)
		{
			if(a[i]==-1) cout<<'-'<<' ';
			else if(a[i]) cout<<'O'<<' ',q++;
			else cout<<'X'<<' ';
		}
		cout<<q<<endl;
	}
	return 0;
}
