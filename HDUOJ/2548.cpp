#include<stdio.h>
main()
{
	double u,v,l,w;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf %lf",&u,&v,&w,&l);
		printf("%.3f\n",l/(u+v)*w);
	}
	return 0;
}