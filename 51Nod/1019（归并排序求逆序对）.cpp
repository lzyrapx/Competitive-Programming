#include<stdio.h>
#include<stdlib.h>
int a[50001];
int b[50001];
int count=0;
int N;
void merge(int *a, int *b, int m, int mid, int n)
{
	int i,j,s;
	i=s=m; j = mid+1;
	while(i<=mid&&j<=n)
	{
		if(a[i]<=a[j]) b[s++] = a[i++];
		else { b[s++] = a[j++]; count += (mid-i+1);}
	}
	while(i<=mid) b[s++] = a[i++];
	while(j<=n) b[s++] = a[j++];
}
void mergesort(int *a, int *b, int i, int j)
{
	int mid;
	if(i<j)
	{
		mid = (i+j)/2;
		mergesort(b,a,i,mid);
		mergesort(b,a,mid+1,j);
		merge(a,b,i,mid,j);
	}
}
int main()
{
	int i,j;
	scanf("%d", &N);
	for(i=0; i<N; ++i) { scanf("%d", &a[i]); b[i] = a[i];}
	mergesort(a,b,0,N-1);
	printf("%d\n", count);
	return 0;
}