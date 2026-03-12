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
	int a[500][500];
    int i=0,j=0,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            for(j=0;j<i+1;j++)
                if(j==0||j==i+1)
                    a[i][j]=1;
        else
            a[i][j]=(a[i-1][j-1]+a[i-1][j]);
        for(i=0;i<n;i++)
            {
                for(j=0;j<i;j++)

                    cout<<a[i][j]<<" ";
                    cout<<a[i][j];
                    cout<<endl;
            }
			cout<<endl;
		}

    return 0;
}