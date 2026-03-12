/*
* this code is made by LzyRapx
* Problem: 1044
* Verdict: Accepted
* Submission Date: 2017-06-06 21:25:07
* Time: 20MS
* Memory: 1724KB
*/
#include <bits/stdc++.h>
using namespace std;
int a[123][123];
int main()
{
    int t;
    cin>>t;
    int cas = 1;
    int n,m;
    while(t--)
    {
        printf("Case #%d: ",cas++);
        cin>>n>>m;
        memset(a,0,sizeof(a));
        int flag = 1;
        int r[123]={0};
        int c[123]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(r[i]<a[i][j])//行 
                {
                    r[i]=a[i][j];
                }
                if(c[j]<a[i][j])//列 
                {
                    c[j]=a[i][j];
                }
            }
        }
        for(int i=0;i<n&&flag;i++)
        {
            for(int j=0;j<m&&flag;j++)
            {
                if(a[i][j] < r[i] && a[i][j] < c[j]){
                    flag = 0;
                }
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}