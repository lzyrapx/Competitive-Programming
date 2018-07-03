#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int m;
set<int>s;
int save[maxn],in[maxn];
int main()
{
	cin>>m;
	if(m==0)return 0*puts("-1");
	for(int i=1;i<=m;i++){
		char c;
		int x;
		scanf(" %c",&c);
		if(c=='?')s.insert(i);
		else
		{
			scanf("%d",&x);
			if(in[x] == (c=='I'))
			{
				set<int>::iterator it = s.lower_bound(save[x]);
				if(it != s.end()) s.erase(it);
				else 
				{
					printf("%d\n",i);
					exit(0);
				}
			}
			else in[x] = (c=='I');
			save[x] = i;
		}
	}
	puts("-1");
	return 0;
}