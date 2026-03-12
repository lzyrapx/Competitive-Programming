#include<bits/stdc++.h>
int main()
{
	char c;
	int n,t=1;
	while(scanf("%c%d",&c,&n)&&c!='@')
	{
		if(t==0)printf("\n");
		t=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=(n+i-1);j++)
			{
				if(j==n-i+1&&i!=n) 
					printf("%c",c);
				else if(j==(n+i-1)&&i!=n)
					printf("%c",c);
				else if(i==n)
					printf("%c",c);
				else
					printf(" ");
			}	
			printf("\n");
		}
		getchar();
	}
}
