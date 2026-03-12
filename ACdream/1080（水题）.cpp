/*
* this code is made by LzyRapx
* Problem: 1080
* Verdict: Accepted
* Submission Date: 2017-06-19 15:32:06
* Time: 0MS
* Memory: 1672KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
char str[123];
int main()
{
    while(~scanf("%s",str+1))
    {
        set<char>s;
        for(int i=1;str[i];i++)
        {
            s.insert(str[i]);   
        }
        if(s.size()&1){
            puts("IGNORE HIM!");
        }
        else
        {
            puts("CHAT WITH HER!");
        }
    }   
    return 0;
}