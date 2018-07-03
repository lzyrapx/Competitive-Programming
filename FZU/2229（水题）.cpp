//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[23][23][23];
int DP[23][23];
int n,ans;
int main()
{  
    int x,y,z;  
    while(~scanf("%d%d%d",&x,&y,&z))  
    {  
        ans=x*3+y*2+z*6;  
        if(ans>=60)  puts("I passed the exam.");  
        else  puts("Exam was too hard.");  
        printf("%d\n",ans);  
    }  
    return 0;  
}   