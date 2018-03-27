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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[50],k=0;
        while(n)
        {
            a[k++]=n%2;
            n=n>>1;
        }
        for(int i=0; i<k; i++)
            if(a[i])
            {
                cout<<i;
                if(i!=k-1)
                    cout<<" ";
            }
        cout<<endl;
    }
	return 0;	
}