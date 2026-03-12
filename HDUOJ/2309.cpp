#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,s,a[101];
    while((cin>>n)&&n)
    {
        s=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=1;i<n-1;i++)
            s+=a[i];
        cout<<s/(n-2)<<endl;
    }
    return 0;
}