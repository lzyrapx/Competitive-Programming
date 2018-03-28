#include <stdio.h>
//×´Ì¬Ñ¹Ëõ 
int w[1010],n,m,q,dp[1010][2048]={0};
int main()
{
	int i,j,end,a,b,t,sum;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++) 
	scanf("%d",&w[i]);
	
	end=(1<<m)-1;
	
	for(i=0;i<n;i++)
		for(j=1;j<=end;j++){
			b=a=(j>>1);
			a|=(1<<(m-1));
			
			t=a;sum=0;
			while(t){
				if(t&1) sum++;
				t>>=1;
			}
			if(sum<=q)
				if((dp[i][j]+w[i+1])>dp[i+1][a]) dp[i+1][a]=dp[i][j]+w[i+1];
			
				
			t=b;sum=0;
			while(t){
				if(t&1) sum++;
				t>>=1;
			}
			if(sum<=q)
				if(dp[i][j]>dp[i+1][b]) dp[i+1][b]=dp[i][j];
		}
		
	int max=0;
	for(i=1;i<=end;i++) if(dp[n][i]>max)
		max=dp[n][i];
	printf("%d\n",max);
	return 0;
}