#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
struct node
{
	char name[23];
	int par;//参数
	int pri;//优先级
	int id;//第几个输入
	friend bool operator < (node a,node b)
	{
		if(a.pri!=b.pri)
		{
			return a.pri > b.pri;//按优先级 升序 
		}
		else return a.id > b.id;//优先级一样的，按 id 升序 
	} 
	
}t;
int main()
{
	
	char c[5],name[23];
	int pout; 
	int cnt = 0;
	int pcmp;//优先级 
	priority_queue<node>q;
	while(~scanf("%s",c))
	{
		if(c[0]=='P')
		{
			scanf("%s %d %d ",name,&pout,&pcmp);
			strcpy(t.name,name);
			t.par = pout;
			t.pri = pcmp;
			t.id = ++cnt;
			q.push(t);
		}
		else
		{
			if(!q.empty())
			{
				t=q.top();
				q.pop();
				printf("%s %d\n",t.name,t.par);
			}
			else
			{
				puts("EMPTY QUEUE!");
			}
		}
	 } 
	return 0;
} 