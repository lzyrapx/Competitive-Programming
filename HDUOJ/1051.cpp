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
struct ac{
	int l,w;
	int flag;
}node[5005];
int cmp(ac a,ac b){
	return a.l<b.l||a.l==b.l&&a.w<b.w;
}
int main()
{
     int n,i,j,count,k,t;
     while(cin>>t){
     	while(t--){
     		count=0;
     		for( i=0;i<5005;i++)
     		node[i].flag=0;
			 cin>>n;
			 for(i=0;i<n;i++){
			 	cin>>node[i].l;
			 	cin>>node[i].w;
		      }
			 sort(node,node+n,cmp);
			 for(i=0;i<n;i++){              //Ì°ÐÄ 
			 	if(node[i].flag==1)continue;
			 	count++; 
			 	k=i;
			 	for(j=i+1;j<n;j++){
			 		if(node[j].l>=node[k].l&&node[j].w>=node[k].w&&node[j].flag==0)
			 		{
			 			node[j].flag=1;
			 			k=j;
			 		}
			 	} 
			 }
			 printf("%d\n",count);
     	}
     }
    return 0;
}