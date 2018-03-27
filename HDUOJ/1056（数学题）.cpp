
#include<cstdio>
int main()
{
	float a=0.0;
	while(1)
	{
	    scanf("%f",&a);
		float sum=0;
		float i=0;
		int count=0;
		if(a==0.00)
		{
			break;
		}
		for(i=2.0;sum<a;i++)
		{
			sum=sum+1/i;
			count++;
		}
		printf("%d card(s)\n",count);
	}
	return 0;
}