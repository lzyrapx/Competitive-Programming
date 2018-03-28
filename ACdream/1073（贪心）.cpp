/*
* this code is made by LzyRapx
* Problem: 1073
* Verdict: Accepted
* Submission Date: 2017-06-19 12:36:12
* Time: 136MS
* Memory: 1668KB
*/
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,sum;
    int s[4];
    int a[1234];
    while(cin>>n)
    {
        for(int i=0;i<4;i++)
        {
            cin>>s[i];//需要的经验 
        }
        sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]; //经验球 
            sum += a[i];
        }
         
        sort(a,a+n);
         
        for(int i=0;i<4;)
        {
            int pos=s[i];
            for(int j=0;j<n;j++)
            {
                if(a[j]>=s[i])
                {
                    sum -= a[j];
                    a[j] = s[i] = 0;
                    break;
                }
            }

            for(int j=n-1;j>=0&&s[i];--j)
            {
                if(a[j])
                {
                    sum -= a[j];
                    s[i] -= a[j];
                    a[j] = 0;
                    break; 
                }
            }
            if(pos==s[i]) break; //还没升级,以后也升不了级
            if(s[i]<=0)i++;
        }
        if(s[3]<=0){
            cout<<"YES"<<" "<<sum<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}