#include<iostream>   
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<queue>
#include<algorithm>  
typedef long long LL;  
using namespace std;
char a; 
int main()
{
	int n;
    while(cin>>n,n)
    {
    	int Rsum=0,Ysum=0;
//题目说中间没出现黑球。。。因为最后一颗球打进才结束比赛 
    	for(int i=0;i<n;i++) 
    	{
    		cin>>a;
    		if(a=='R')Rsum++;
    		if(a=='Y')Ysum++;
    		if(a=='B')
    		{
    			if(Rsum==7)puts("Red");
    			else puts("Yellow");
			}
			if(a=='L')
			{
				if(Ysum==7) puts("Yellow");
				else puts("Red");
			}
		}
		
	}
	return 0;
}
