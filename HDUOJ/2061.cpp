#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	
	double s,z,k,shu;
	char c[31];
	int t,i,n,o;
	scanf("%d",&t);
	while(t--)
	{
		o=0;
		scanf("%d",&n);
		getchar();
		for(i=0,shu=0,z=0;i<n;i++)
		{
			scanf("%s %lf %lf",c,&k,&s);
			getchar();
			z=z+k*s;
			shu=shu+k;
			if(s<60&&s>=0)
			{
				o=1;
			}
		}
		if(o==1)
			printf("Sorry!\n");
		else
			printf("%.2lf\n",z/shu);
		if(t!=0)
			cout<<endl; 
	}
    return 0;
}