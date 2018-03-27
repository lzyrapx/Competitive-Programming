#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;

int main()
{
	int t,s,m;
    while(scanf("%d",&t),t){
              m=0;
        while(t--){

        scanf("%d",&s);
        m^=s;        //异或求独特数
        }
        printf("%d\n",m);
    }
	return 0; 
}

----------------
include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n){
		int a[2000],i;
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		for(i=1;i<n;i++)
		if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
			cout<<a[i]<<endl;
			break;
		}
	}
	return 0;
}