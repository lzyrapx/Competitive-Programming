#include<bits/stdc++.h>
using namespace std;

struct node
{
	int p,d;
};
struct cmp
{
	bool operator()(const node a,const node b)
	{
		if(a.p!=b.p)return a.p>b.p;
		else return a.d>b.d;
	}
};
int t;
int N;
node stone;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		priority_queue<node,vector<node>,cmp>q;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&stone.p,&stone.d);
			q.push(stone);
		}
		int flag=1;
		while(!q.empty())
		{
			stone = q.top();
			q.pop();
			if(flag)
			{
				stone.p += stone.d;
				q.push(stone);
			}
			flag=!flag;//偶数就跳过 
		}
		printf("%d\n",stone.p);
	}
}