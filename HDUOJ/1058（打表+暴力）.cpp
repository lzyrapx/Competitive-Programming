
#include <cstdio>
#define min(a,b) ((a) < (b) ? (a):(b))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
int a[5850];
int main(void)
{
	int n = 1;
	int p2,p3,p5,p7;
	p2 = p3 = p5 = p7 = 1;
	a[1] = 1;
	while(a[n] < 2000000000)
	{
		a[++n] = min4(2 * a[p2],3 * a[p3], 5 * a[p5], 7 * a[p7]);
		if(a[n] == 2 * a[p2])
			p2++;
		if(a[n] == 3 * a[p3])
			p3++;	
		if(a[n] == 5 * a[p5])
			p5++;
		if(a[n] == 7 * a[p7])
			p7++;
	}
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		printf("The %d",n);
		int ten = n/10%10;
		if(n%10 == 1 && ten != 1)
			printf("st");
		else if(n%10 == 2 && ten != 1)
			printf("nd");
		else if(n%10 == 3 && ten != 1)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n",a[n]);
	}
	return 0;
}