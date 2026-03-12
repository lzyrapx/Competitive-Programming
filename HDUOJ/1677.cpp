#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct doll
{
	int w,h;
};
bool cmp(struct doll a,struct doll b)
{
	if(a.w!=b.w) return a.w<b.w; //ÉýÐò w
	else return a.h>b.h; //½µÐò h 
}
int main()
{
	int t;
	doll p[20005],team[20005];
    scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&p[i].w,&p[i].h);
		}
		sort(p,p+n,cmp);
		int count=0;
		
		for(int i=0;i<n;i++)  
        {  
            int flag=0;  
            
            for(int j=0;j<count;j++)  
            {  
                if(p[i].w>team[j].w && p[i].h>team[j].h)  
                {  
                    team[j]=p[i];  
                    flag=1;  
                    break;  
                }  
            }  
            
            if(flag==0) 
			{
				team[count++]=p[i];
				//printf("%d\n",p[i]);
			}
        }  
        printf("%d\n",count);  
	}
	return 0;
}