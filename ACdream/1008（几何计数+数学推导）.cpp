/*
* this code is made by LzyRapx
* Problem: 1008
* Verdict: Accepted
* Submission Date: 2017-06-05 10:14:57
* Time: 20MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
//当n>6的时候，不会有内三角形出现
int main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        cas++;
        int n;
        cin>>n;
        printf("Case #%d: ",cas);
         
        if(n==1){
            cout<<0<<endl;
        }
        else if(n==2){
            cout<<0<<endl;
        }
        else if(n==3){
            cout<<1<<endl;
        }
        else if(n==4)
        {
            cout<<8<<endl;
        }
        else if(n==5)
        {
            cout<<35<<endl;
        }
        else if(n==6){
            cout<<32<<endl;
        }
        else
        {
            cout<<(5*n)%20121111<<endl;//¸ù±¾²»ÓÃÈ¡Ä£ 
        }
    }
    return 0;
}