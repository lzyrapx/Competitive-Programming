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

int main()
{
	int n;
	int a[10001]={0};
	while(cin>>n){
		int sum=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]%2==1)
			  sum=sum*a[i];
		}
		printf("%d\n",sum);
	}

	return 0;

}

