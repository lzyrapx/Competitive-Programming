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

int main()
{
   string ch;
   int len,i,n;
   while(getline(cin,ch)&&ch!="#")
   {
   	    n=0;
   	    len=ch.size();
   	    for(i=0;i<len-1;i++)
   	      {
   	      	if(ch[i]=='1')n++;
			 }
   	    
   	    if(ch[i]=='e')
   	    {
   	    	if(n%2==0) ch[i]='0';
   	    	else ch[i]='1';
		   }
		   else if (ch[i]=='o')
		   {
		   	if(n%2==0)ch[i]='1';
		   	else ch[i]='0';
		   }
		   	cout<<ch<<endl;
   	    
   }
   
    return 0;
}

