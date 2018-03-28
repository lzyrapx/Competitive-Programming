# include <stdio.h>
# include <math.h>
int main()
{
	int t;
	double a,b,c,d,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		s=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		printf("%.1f\n",s);
	}
	return 0;
}