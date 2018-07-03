#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100000+10;
int n;
ll l[N],cost[N];
char c;
struct node
{
	ll first,second;
}p;
bool operator<(node a,node b)
{
	if(a.second==b.second)return a.first<b.first;
	return a.second>b.second;
}
priority_queue<node>que;
/*
从左到右有n个连续的组，每一组有Li个括号，
要么全是左括号，要么全是右括号，
以及该组的每一个左括号翻成右括号，
或者右括号翻成左括号的花费Di.可
以对这n个组的括号进行翻转，每一个括号都可以选择翻或者不翻，
使整个括号序列是一个合法括号序列.
*/
int main()
{
	while(~scanf("%d",&n))
	{
		ll ans = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d %c %I64d",&l[i],&c,&cost[i]);
			if(c=='(')//全部翻成右括号 
			{
				ans+=l[i]*cost[i];
				cost[i]=-cost[i];
			}
		}
		while(!que.empty())
		{
			que.pop();
		}
		ll k = 0;
		ll tot = 0;	
		ll ret = 0;
		for(int i=1;i<=n;i++)
		{
			p.first = l[i];
			p.second = cost[i];
			
			que.push(p);//放进堆里 
			//计算这个位置需要多少个左括号 
			tot += l[i];
			ret = (tot + 1) /2 - k; ///至少还要有 k个左括号 
			k = ( tot + 1) /2 ;	//当前有ret个左括号 
			while(ret > 0 && !que.empty())
			{
				p=que.top();
				que.pop();
				
				ll ch_right_num= min(p.first,ret);
				ret -= ch_right_num;
				
				ans += ch_right_num * p.second;//翻成左括号 
				p.first  -= ch_right_num;
				
				if(p.first > 0 )
					que.push(p);
			}
		}
		
		printf("%I64d\n",ans);
	}
	return 0; 
}
