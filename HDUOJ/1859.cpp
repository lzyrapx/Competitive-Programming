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
	int x,y,minX,minY,maxX,maxY;
    while(scanf("%d %d",&x,&y),x||y)
    {
        minX=x,minY=y;
        maxX=x,maxY=y;
        while(scanf("%d %d",&x,&y),x||y)
        {
            minX=min(minX,x);
            minY=min(minY,y);
            maxX=max(maxX,x);
            maxY=max(maxY,y);
        }
        printf("%d %d %d %d\n",minX,minY,maxX,maxY);
    }
	return 0;
} 