#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main()
{
   double n,m;
    while(cin>>n>>m)
   {
   	  int time=0;
   	  int t=1;
   	  int flag=0;
   	  while(flag==0)
	{  	  	
		for(int i=1;i<=t;i++) //t为水滴数 
   	    {
   	  	  n=n-m; 
   	  	  ++time;
   	  	  if(n<=0){
   	  	 	flag=1;
   	  	 	break;
   	      }  	      
   	     }
   	     if(flag==1)break;
   	   	  ++t; //下一次滴的水滴+1 
   	   	  time++;  //停一次 
   	}  
   	  printf("%d\n",time);
   } 
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(  )
{
	double v,d;
	int s,n;
	while( scanf( "%lf%lf",&v,&d ) != EOF )
	{
		s = 0,n = 1;
		while( v / d > n )//(v>n*d)就不能过 
		{
			v -= n*d;
			s += n;
			s++;
			n++;
		}
		s += ceil( v/d );
		printf( "%d\n",s );
	}
	return 0;
}
*/