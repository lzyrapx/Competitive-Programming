//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char mp[12][12];  
int main()  
{  
    int t;  
    cin>>t;
    while(t--)  
    {  
        int s_x,s_y,e_x,e_y;  
        for(int i=0;i<4;i++)
			for(int j=0;j<8;j++)
			{
				cin>>mp[i][j];
			}
        for(int i=0;i<4;i++)  
        {  
            for(int j=0;j<8;j++)  
            {  
                if(mp[i][j]=='.')  
                {  
                    s_x=i;
					s_y=j;  
                }  
                if(mp[i][j]=='*')  
                {  
                    e_x=i;
					e_y=j;  
                }  
            }  
        }  
        int tmp=abs(e_x-s_x)+abs(e_y-s_y);  
        if(tmp%2==1)  puts("Red win");  
        else puts("Black win");  
    }  
    return 0;  
}  