#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}edge[123];
int main()
{
	int n;
	while(cin>>n)
	{
		int L,R;
		//string s;
		char s[1234];
		cin>>L>>R;
		for(int i=0;i<n;i++)
		{
			cin>>edge[i].x>>edge[i].y;
		//	cin>>s;
			gets(s);
		}
		sort(edge,edge+n,[](const node &a,const node &b){
   			if(a.y==b.y) return a.x>b.x;
    		return a.y>b.y;});
    //	for(int i=0;i<n;i++)cout<<edge[i].x<<" "<<edge[i].y<<endl;
    	for(int i=0;i<n;i++)
		{
    		if(L>R)break;
    		if(R>edge[i].y)break;
    		else if(R<=edge[i].y)
    		{
    			R=edge[i].x-1;
			}
		}
		if(L>R)puts("Badly!");
		else printf("%d\n",R); 
	}
	return 0;
 } 