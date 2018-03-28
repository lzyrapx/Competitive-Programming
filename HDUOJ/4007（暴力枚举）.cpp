#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int x,y;
	
}node[1005];
int xx[1005],yy[1005];
int xcnt,ycnt;
int N,R;
int main()
{
	while(~scanf("%d%d",&N,&R))
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d", &node[i].x, &node[i].y);
			yy[i]=node[i].y;
		}
		sort(yy+1,yy+1+N);
		int e,ans=0;
    	for(int i=1;i<=N;i++)
    	{
        	xcnt=0;
        	for(int j=1;j<=N;j++) 
        	{
            	if(node[j].y >= yy[i] && node[j].y <= yy[i]+R)
                xx[xcnt++]=node[j].x;
        	}
        	sort(xx,xx+xcnt);
        	xx[xcnt++]=2e9;
        	e=0;
        	for(int j=0;j<xcnt-1;j++)
        	{
            	while( xx[e] <= xx[j]+R ) e++;
            	ans=max(ans,(e-j));
        	}
    	}
     	printf("%d\n",ans);		
	}
	
	return 0;
}