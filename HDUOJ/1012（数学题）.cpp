#include<iostream>
#include<cstdio>
int f(int n)
{
	int i,t;
	if(n==0) return 1;
	t = 1;
	for(i=1;i<=n;i++) t *= i;
	return t;
} 
int main()
{
	int i,j,n;
	double t,r;
	printf("n e\n");
	printf("- -----------\n");
	for(i=0;i<=9;i++)
	{
		t = 0.0;
		for(j=0;j<=i;j++)
			t += 1.0/f(j);
		if(i==0||i==1)printf("%d %.0f\n",i,t);
		else if(i==2)printf("%d %.1f\n",i,t);
		else printf("%d %.9lf\n",i,t);
	}
	return 0;
}