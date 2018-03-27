#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
const double PI=3.14;
int main()
{
	int R;
	double S;
	double A,B;
	while(cin>>R)
	{
		if(R==0)
			break;
		S=PI*R*R;
		S=S/3;
		A=sqrt(S/PI);
		B=sqrt((2*S)/PI);
		printf("%.3lf %.3lf\n",A,B);
	}
	return 0;
}