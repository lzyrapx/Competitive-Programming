/*
* this code is made by LzyRapx
* Problem: 1013
* Verdict: Accepted
* Submission Date: 2017-06-05 15:10:02
* Time: 4MS
* Memory: 1668KB
*/
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int  n;
    string s;
     while(cin>>n>>s)
     {
         int len = s.size();
         int diff = n-len;
          int L=0,R=0;
         for(int i=0;i<s.size();i++)
         {
               if(s[i]=='L'){
                     L++;
                 }
                else{  R++; }
         } 
        cout<<diff+L<<" "<<L<<endl;   
     }
     return 0;
}