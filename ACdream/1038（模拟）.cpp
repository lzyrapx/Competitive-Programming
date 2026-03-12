/*
* this code is made by LzyRapx
* Problem: 1038
* Verdict: Accepted
* Submission Date: 2017-06-06 14:23:15
* Time: 4MS
* Memory: 5592KB
*/
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e6+10;  
char s[MAXN], source[MAXN], target[MAXN], ans[MAXN];  
map<char, int> mps;  
map<int, char> mpt;  
long long q_pow(int n,int k)
{
    long long ans=1;
    while(k)
    {
        if(k&1) ans=ans*n;
        k>>=1;
        n=n*n;
    }
    return ans;
}
int main()  
{  
    int t, cas= 1;  
    cin>>t;
    getchar();  
    while(t--)  
    {  
        mps.clear();
        mpt.clear();  
        scanf("%s", s);  
        scanf("%s", source);  
        scanf("%s", target);
        int len1 = strlen(s);    
        int len2 = strlen(source);
        int len3 = strlen(target);  
         
        for(int i=0; i<len2; i++)  
        {  
            mps[source[i]] = i;  
        }  
        for(int i=0; i<len3; i++)  
        {  
            mpt[i] = target[i];  
        }  
        int res = 0;  
        for(int i=0; i<len1; i++)  
        {  
             res += q_pow(len2,i)*mps[s[len1-i-1]];
         //   cout<<"res="<<res<<endl;
             
        }  
   //  cout<<"res="<<res<<endl;
        if(res==0)  
        {  
            printf("Case #%d: ", cas++);  
            printf("%c\n", target[0]);  
            continue;  
        }  
        int cnt = 0;  
        while(res)  
        {  
            ans[cnt++] = mpt[(res%len3)];  
            res /= len3;  
        }  
         
        printf("Case #%d: ", cas++);  
        for(int i=cnt-1; i>=0; i--) cout<<ans[i];
        cout<<endl;
    }  
    return 0;  
}