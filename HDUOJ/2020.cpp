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
//int cmp(int x,int y){
//	return x>y;
//}
int main()
{
	int n,i,j,a[100],t;
    while((scanf("%d",&n)!=EOF),n)
    {
	for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n-1;i++)
	    for(j=0;j<n-1;j++)
	        if(fabs(a[j])<fabs(a[j+1]))
	        {
		    swap(a[j],a[j+1]);
	        }
	for(i=0;i<n;i++)
	{
        if(i==n-1) printf("%d\n",a[n-1]);
	    else printf("%d ",a[i]);

	}
   }
	return 0;
}