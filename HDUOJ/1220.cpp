#include<stdio.h>
#include<iostream>
int main()
{
	int n;
	while(std::cin>>n)
	{
		std::cout<<(n*n*n*(n*n*n-1))/2-3*(n*n)*(n-1)<<std::endl;
	}
	return 0;
}