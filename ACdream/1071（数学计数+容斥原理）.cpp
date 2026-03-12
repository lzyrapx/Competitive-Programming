/*
* this code is made by LzyRapx
* Problem: 1071
* Verdict: Accepted
* Submission Date: 2017-06-08 17:02:59
* Time: 1444MS
* Memory: 3112KB
*/
#include <bits/stdc++.h>
using namespace std;
int a[123456];
long long cnt[123456];
int main()
{
    long long n;
    while(cin>>n)
    {
         
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[a[i]] ++;
        }
        long long num = 0;
        num= n*(n-1)/2;
        for(long long i=1;i<=123456;i++)
        {
            if(cnt[i]!=0)
            {
                num -= ( cnt[i] * (cnt[i]-1)/2 );
                for(long long j = i+i;j<=123456;j+=i)
                {
                    num -= (cnt[j] * cnt[i]);
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}