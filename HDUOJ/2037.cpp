#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
struct inp
{
	int x,y;
}node[105];
int cmp(inp a,inp b){
	return a.y<b.y;
}
int main()
{
	int n;
     while(cin>>n)
	 {
	 	if(n==0)break;
	 	for(int i=0;i<n;i++){
	 		cin>>node[i].x>>node[i].y;
	 	}
	 	sort(node,node+n,cmp);
		int j=0; int sum=1;
		 for(int i=1;i<n;i++){
		 	if(node[i].x>=node[j].y)
		 	{
		 		sum++;
		 		j=i;
		 	} 
		 } 
		 printf("%d\n",sum);
	 } 
    return 0;
}
