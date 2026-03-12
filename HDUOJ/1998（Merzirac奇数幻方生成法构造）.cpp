#include<cstdio>
using namespace std; 
//Merzirac奇数幻方生成法
int main()
{
	int n;
	int d[20][20];
	int t;
	int i,j,k,stx,sty,x,y;
	scanf("%d",&t);
    while(t--)
   {
 	 scanf("%d",&n);
	 stx=0;//行 
	 sty=(n+1)/2-1;//列 
	 for(k=1;k<=n*n;k++)
	 {
		x=stx--;
		y=sty++;		
		d[x][y]=k;

		if(k%n==0)
		{
			stx=stx+2;
			sty=sty-1;
		}
		if (stx<0)
			stx=n-1;
		if(sty>=n)
			sty=0;

	 }
	 
	 for(i=0;i<n;i++)
	 {
		for(j=0;j<n;j++)
		{
			printf("%4d",d[i][j]);
		}
		printf("\n");
	 }
   } 
   return 0;
	
}