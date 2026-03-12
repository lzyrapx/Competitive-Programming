/*
* this code is made by LzyRapx
* Problem: 1006
* Verdict: Accepted
* Submission Date: 2017-06-23 15:52:35
* Time: 28MS
* Memory: 1844KB
*/

//http://blog.csdn.net/liangzhaoyang1/article/details/73648994
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double A,B;
        cin>>A>>B;
        if(A>B)
        {
            printf("%.5lf\n",A - 1 + log2( pow(2.0,B - A) + 1 ));
        }
        else
        {
            printf("%.5lf\n",B - 1 + log2( pow(2.0,A - B) + 1 ));
        }
    }
    return 0;
}