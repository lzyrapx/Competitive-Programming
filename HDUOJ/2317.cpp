#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,c,r,m;
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%d%d%d",&c,&r,&m);
	    if(r-m>c)
	    printf("advertise\n");
	    else if(r-m==c)
	    printf("does not matter\n");
	    else
	    printf("do not advertise\n");
	}
	return 0;
}