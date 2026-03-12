#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    int t,n;
    __int64 m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=pow(3,n-1)+1;
        printf("%I64d\n",m);
    }
    return 0;
}