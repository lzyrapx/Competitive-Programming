/*
RunID: 751876User
ID: LzyRapx
Submit time: 2017-06-12 09:51:03
Language: C++
Length: 857 
Bytes.Result: Accepted
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int w,num,len;
const int N=200000+10;
int a[N]; 
int b[N];
int check(int n)
{ 
	for(int i=1;i<=n;i++)b[i]=a[i];
	sort(b+1,b+1+n);
	int cnt = 0;
	b[0] = 0;
	b[n+1] = w+1; 
	for(int i=0;i<=n;i++){
		cnt+=(b[i+1]-b[i])/(len+1); 
	}
	if(cnt >= num) return 1;
	return 0;
}
int main()
{
	while(cin>>w>>num>>len)//地图长度，战舰数，战舰长度 
	{		
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)//炮弹的位置 
		{
			scanf("%d",&a[i]);
		} 
		int l = 1, r = n;
		int mid;
		while(l<=r)
		{ 
			mid = (l+r)>>1;
			if(check(mid)){ 
				l = mid+1;
			}
			else
				r = mid-1;
		}
		if(check(n))  puts("-1");
		else cout<<l<<endl;
	}
	return 0;
}