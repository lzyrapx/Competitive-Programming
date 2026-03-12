/*
* this code is made by LzyRapx
* Problem: 1099
* Verdict: Accepted
* Submission Date: 2017-06-20 15:48:48
* Time: 1192MS
* Memory: 21200KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
int a[maxn];
int main()
{
    int n;
    int m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        nth_element(a , a + n - m, a + n);
        printf("%d\n",a[n - m]);
    }
    return 0;
}