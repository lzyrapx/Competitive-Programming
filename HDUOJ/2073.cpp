#include<iostream>     
#include<cstdlib>    
#include<cstdio>    
#include<cmath>    
#include<cstring>    
#include<string>    
#include<cstdlib>    
#include<iomanip>    
#include<vector>    
#include<list>    
#include<map>    
#include<queue>  
#include<algorithm>    
using namespace std;

int main()
{
	int N,x1,y1,x2,y2,t,s;
	double sum;
	while(scanf("%d",&N)!=EOF)
	{
		while(N--)
		{
			sum=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2&&y1==y2)
			{
				printf("%.3f\n",sum); //输出 0 
				break;
			}
			if(x1+y1>x2+y2)  
			{
				swap(x1,x2);
				swap(y1,y2);
			}
			else if(x1+x2==x2+y2)
			{
				if(x1>x2)
				{
				  	swap(x1,x2);
				  	swap(y1,y2);

				}
			}
			//模拟 
			while(1)
			{
				if(y1==0)
				{
					sum=sum+sqrt((x1*x1)+(x1+1)*(x1+1));
					y1=x1+1;
					x1=0;
					
				}
				else
				{
					sum=sum+sqrt(2);
					x1++;
					y1--;
				}
				//到达终点 
				if(x1==x2&&y1==y2)
					break;
				
			}
			printf("%.3f\n",sum);
		}
	}
	return 0;
}