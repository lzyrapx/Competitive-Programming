#include<stdio.h>
int main()
{
	int num[20] = {3,7,17,41,99,239,577,1393,3363,8119,19601,47321,114243,275807,665857,1607521,3880899,9369319,22619537,54608393};
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", num[n-1]);
	}
	return 0;
}

-----------------
TLE:
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int maps[42][22];
int sum;
int d[3][2]={{-1,0},{1,0},{0,1}}; //×ó£¬ÓÒ£¬Ç° 
int dfs(int n,int m,int steps)
{
   
   if(steps==0)
   {
    sum++;
    return 0;
    
   }
    
   for(int i=0;i<3;i++)
   {
      if(maps[n+d[i][0]][m+d[i][1]]==0)
     {
     	maps[n+d[i][0]][m+d[i][1]]=1; 
		                                 
      	dfs(n+d[i][0],m+d[i][1],steps-1);
      	
      	maps[n+d[i][0]][m+d[i][1]]=0;
     }
   }
} 
     
int main()
{    
     int t,steps,i;
     scanf("%d",&t);
     while(t--)
     {
      memset(maps,0,sizeof(maps));
      sum=0;
      scanf("%d",&steps);
      maps[20][0]=1;
      dfs(20,0,steps);
      printf("%d\n",sum);
      }
     
     return 0;
}