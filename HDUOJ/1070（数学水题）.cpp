#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int T,day;
	scanf("%d",&T);
	while(T--)
	{
		int percost=9999999,val=0,n;
		string  s;
		string ans;
		cin>>n;
		while(n--){
			int cost,v,day;
			cin>>s>>cost>>v;
			if(v<200)continue;
			day=v/200;
			if(day>5)day=5;
			if(cost/day<percost||(cost/day == percost&&v>val))
			{
				percost=cost/day;
				val=v;
				ans=s;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}