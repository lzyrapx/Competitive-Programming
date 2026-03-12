#include<stdio.h>
int main()
{
    int i,j,k,l;
    int n,t;
    while (scanf("%d",&n)!=EOF)
    {
        t=0;
        for (int i=0;i*50<=n;i++)
            for (int j=0;j*25<=n;j++)
                for (int k=0;k*10<=n;k++)
                    for (int l=0;l*5<=n;l++)
                        if (n-i*50-j*25-k*10-l*5>=0&&i+j+k+l+n-i*50-j*25-k*10-l*5<=100)
                        t++;
        printf("%d\n",t);
    }
    return 0;
}

-----------------------------------------------

#include<stdio.h>
int main()
{
	int ans,n,i,j,k,a[5]={50,25,10,5,1};
	int dp[251][101]={0};
	dp[0][0]=1;
	for (i=0;i<5;i++)
		for (j=0;j<=250;j++)
			for (k=0;k<100;k++)
				if (a[i]+j<=250)
					dp[a[i]+j][k+1]+=dp[j][k];
				else
					break;
	
	while (scanf("%d",&n)==1)
	{
		ans=0;
		for (i=0;i<=100;i++)
			ans+=dp[n][i];
		printf("%d\n",ans);
	}
	return 0;
}