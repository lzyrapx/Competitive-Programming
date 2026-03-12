/*
中国剩余定理
 已知(n+d)%23=a;   (n+d)%28=b;   (n+d)%33=c
 
 使33×28×a被23除余1，找a使用33×28×a整除33×28，33×28×6=5544。（以下都是） 
 使23×33×b被28除余1，用23×33×19=14421。 
 使23×28×c被33除余1，用23×28×2=1288。 
 因此有（5544×p+14421×e+1288×i）% lcm(23,28,33) =n+d 
 又23、28、33互质，即lcm(23,28,33)= 21252;
 所以有n=（5544×p+14421×e+1288×i-d）%21252
 本题所求的是最小整数解，避免n为负，因此最后结果为n= [n+21252]% 21252
 */
#include<bits/stdc++.h>
int main()
{	
	int p,e,i,d,n,T;
	int cas,k;
	scanf("%d",&T);
	while(T--)
	{	
	    cas=1;
		getchar();	
		while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF)
		{ 
			if(p==-1&&e==-1&&i==-1&&d==-1)break;
			else
			{	
			    n=(5544*p+14421*e+1288*i-d+21252)%21252;
				if(n==0) n=21252;
				printf("Case %d: the next triple peak occurs in %d days.\n",cas++,n);
			}
		}
		if(T!=0)
			printf("\n");
	}
	return 0;
}