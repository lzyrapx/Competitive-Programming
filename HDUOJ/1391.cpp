#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main()
{
    int x,y,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        if(x==y)
		 x%2==1? printf("%d\n",x+x-1):printf("%d\n",x+x);
        else if(x-y==2) 
		x%2==1?printf("%d\n",x+y-1):printf("%d\n",x+y);
        else printf("No Number\n");
    }
    return 0;
	
}