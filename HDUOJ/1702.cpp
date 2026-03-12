#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,tmp;
		scanf("%d",&N);
		char str[10];
		scanf("%s",str);
		if(!strcmp(str,"FIFO"))
		{
			queue<int> q;
			for(int i=0;i<N;i++)
			{
				scanf("%s",str);
				if(!strcmp(str,"IN"))
				{
					scanf("%d",&tmp);
					q.push(tmp);
				}
				else if(!strcmp(str,"OUT"))
				{
					if(q.empty())
					{
						printf("None\n");
					}
					else
					{
						printf("%d\n",q.front());
						q.pop();	
					}
					
				}
			}
		}
		else if(!strcmp(str,"FILO"))
		{
			stack<int> s;
			for(int i=0;i<N;i++)
			{
				scanf("%s",str);
				if(!strcmp(str,"IN"))
				{
					scanf("%d",&tmp);
					s.push(tmp);
				}
				else if(!strcmp(str,"OUT"))
				{
					if(s.empty())
					{
						printf("None\n");
					}
					else
					{
						printf("%d\n",s.top());
						s.pop();
					}
					
				}
			}
		}
		
	}
	return 0;
}