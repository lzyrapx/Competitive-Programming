#include <bits/stdc++.h>
using namespace std;

int main()
{
	double r,w,h;
	int cas=0;
	while(cin>>r>>w>>h)
	{
		if(r==0)break;
		cas++;
		if(sqrt(w*w+h*h)<=2*r)
		{
			printf("Pizza %d fits on the table.\n",cas);
		}
		else 
		{
			printf("Pizza %d does not fit on the table.\n",cas);
		}
	}
	return 0;
}