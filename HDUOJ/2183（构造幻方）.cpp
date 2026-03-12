#include <bits/stdc++.h>
//首先找出1的位置，在第n/2+2行，第n/2+1列，依次往右下填数
//如果当前所填的i符合i%n==0，i+1填在当前位置的下两行，越界则循环。
int main()
{  
  int x,y,n,a[25][25];
  int i,j;
   while(~scanf("%d",&n),n)
   { 
      x=n/2+1;
	  y=n/2;
      i=1;
      
      while(i<=n*n)
     {
	    a[x][y]=i;
        if(i%n==0)
	   {
	   	 x=x+2; 
	   }
       else
       {
      	 x=x+1;
		 y=y+1;
	   }
       
       if(x>n-1) x=x-n;
       if(y>n-1) y=y-n;
        i++;
     }
     
     for(i=0;i<n;i++)
     {
	   for(j=0;j<n;j++)
	   {
	   	 printf("%4d",a[i][j]);
	   } 
       printf("\n"); 
     } 
   }
   return 0;
}