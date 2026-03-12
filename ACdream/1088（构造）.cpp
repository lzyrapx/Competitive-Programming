/*
* this code is made by LzyRapx
* Problem: 1088
* Verdict: Accepted
* Submission Date: 2017-06-20 10:33:42
* Time: 4MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m=1;
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(i==1){
                cout<<n;
            }
            else
            {
                if(flag){
                    cout<<" "<<m++;
                    flag = false;
                }
                else
                {
                    cout<<" "<<n-(m-1);
                    flag = true;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}