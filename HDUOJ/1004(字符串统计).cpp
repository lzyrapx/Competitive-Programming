#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string a[1000];
	int T=0,k=0,i,j;
    while(cin>>T){
		if(T==0)break;
		int b[1000]={0};
		for( i=1;i<=T;i++){
		//	scanf("%s",&a[i]);
		cin>>a[i];
		}
		for(i=1;i<=T;i++)for( j=1;j<=T;j++){
			if(a[i]==a[j]){
			b[i]++;
			}
			
		}
		int maxx=0;
			for( i=1;i<=T;i++){
				if (b[i] > b[maxx]) 
				maxx = i;
			}
		//	printf("%s",a[max]);
		cout<<a[maxx]<<endl;
	}
	return 0;
}