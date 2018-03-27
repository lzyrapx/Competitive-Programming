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
	int n, m, a[128], b[128], i, j;
    while(scanf("%d %d", &n, &m), (n || m))
    {
        for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
        for(i = 0; i < m;i++)
		 scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+m);
        
        int f=0,j=0,sum;
        for(i=0; i < n; i++)
        { 
             sum=0; 
            for(j=0;j<m;j++) 
              {
              	if(a[i]!=b[j])
              	 sum++;
              }
              //cout<<sum<<endl;
              if(sum==m)
              printf("%d ",a[i]);
              else f++;
        }      
        if(f==n) printf("NULL");
        printf("\n");
    }
    return 0;
}