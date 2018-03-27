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
    int n;
    int m=1;
    while(cin>>n)
    {
        int j;
        if(n<0)break;
        if(m>1)cout<<endl;
        cout<<"Case "<<m++<<"."<<endl;
        if(n==1)cout<<"1 1 ";
        for(int i=2;i<=sqrt(n);i++)
        {
            j=0;
            while(n%i==0)
            {
                n=n/i;
                j++;
            }
            if(j)
            cout<<i<<" "<<j<<" ";
        }
        if(n!=1)
        cout<<n<<" "<<"1"<<" ";
        cout<<endl;
    }
    return 0;
}