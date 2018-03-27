#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50005];  
ll sum[50005];  
int main()  
{  
    int n;  
    cin>>n;  
    for(int i=1;i<=n;i++)  
    {  
        cin>>a[i];  
        sum[i]=sum[i-1]+a[i];  
    }  
    int q;  
    cin>>q;  
    while(q--)  
    {  
        int x,y;  
        cin>>x>>y;  
        cout<<sum[x+y-1]-sum[x-1] <<endl;  
    }  
    return 0;  
}