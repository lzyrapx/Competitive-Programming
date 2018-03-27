#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int main(){
	int i,j,m,n;
	int a[3]={150,200,350};
	int dp[10001];
	cin>>n;
	while(n--){
		memset(dp,0,sizeof(dp));
		cin>>m;
		for(i=0;i<3;i++){
			for(j=a[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}
	//	for(int k=0;k<=m;k++){
	//		cout<<dp[k]<<" ";
	//	}
		cout<<m-dp[m]<<endl;
	}	
	return 0;
	 
}