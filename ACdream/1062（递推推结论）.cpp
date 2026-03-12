/*
* this code is made by LzyRapx
* Problem: 1062
* Verdict: Accepted
* Submission Date: 2017-07-14 12:20:28
* Time: 536MS
* Memory: 2056KB
*/
/*
a[i] = i * i - i + 2;
(1)、a(0) = 1, a(1) = 2, a(2) = 4, a(3) = 8
(2)、当n>3时，每增加一个面，这面就要与前面n-1个面都相交，
因为过同一点，两平面如果有一个公共点就有一条公共直线，
这样就会把前面平面划分的空间一分为二，a(n) - a(n-1)=2 * (n-1),
然后累加得a(n)=n^2-n+2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50000;  
ll a[maxn];  
void init()
{  
    a[0]=1;a[1]=2;a[2]=4;a[3]=8;  
    for(int i=1;i<maxn;i++){
         a[i]=i*i-i+2;
    } 
        
}  
int main()
{
    int t;
    init();
    cin>>t;
    while(t--)
    {
        ll n=0;
        scanf("%lld",&n);
        ll ans = 0;
        if(n==0){
            puts("1");
            continue;
        }
        else
        {
            while(a[ans]<n)ans++;
            printf("%lld\n",ans);
        }
    }
    return 0;   
}