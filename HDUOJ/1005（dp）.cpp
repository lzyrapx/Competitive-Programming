#include<iostream>
#include<cstdio>
int main()
{
	int a,b,n;
	while(~scanf("%d%d%d",&a,&b,&n)){
		if(a==0&&b==0&&n==0)break;
		int arr[48];
        arr[1]=1;
        arr[2]=1;
        for(int i=3;i<48;i++)
            arr[i]=((a*arr[i-1]+b*arr[i-2])%7);
        printf("%d\n",arr[n%48]);

	}
}