#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,m;
    while (cin>>n>>m){
    	if(m==0&&n==0)break;
        int a[101];
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        a[n]=m;
        sort(a,a+n+1);
        for (int i=0; i<n+1; i++) {
            if(i>0){
                cout<<" ";
            }
            cout<<a[i];
        }
        cout<<endl;
    }

	return 0;
}