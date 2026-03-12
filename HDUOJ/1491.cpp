#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int i,j,k,l,m,n,x,y;
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		m=0;
		for(i=0;i<x-1;i++)
		m+=a[i];
		m+=y;
		if(m==294)
		printf("It's today!!\n");
		if(m>294)
		printf("What a pity, it has passed!\n");
		if(m<294)
		printf("%d\n",294-m);
	}
	return 0;
}