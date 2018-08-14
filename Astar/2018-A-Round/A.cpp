#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int a[maxn];
int main()
{
    int n;
    while(std::cin >> n)
    {
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans=-1;
        for(int i=0;i<n-2;i++) {
            if(a[i]+a[i+1]>a[i+2]) {
                ans=a[i]+a[i+1]+a[i+2];
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
