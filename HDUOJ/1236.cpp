#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

struct stu{
	string na;
	double sco;
}s[1010];
bool cmp(stu a,stu b){
	if(a.sco==b.sco)
		return a.na<b.na;
	return a.sco>b.sco;
}
int main(){
	int n,i,j,m,x,ans;
	double g,a[20];
	while(scanf("%d",&n),n){
		
		scanf("%d%lf",&m,&g);
		
		for(i=1;i<=m;i++)
			scanf("%lf",&a[i]); //每题的分数 
		ans=0;
		
		for(i=0;i<n;i++){  
			cin>>s[i].na;      //准考证号 
			scanf("%d",&m);     
			s[i].sco=0;
			for(j=0;j<m;j++){    //做的题目的编号 
				scanf("%d",&x);
				s[i].sco+=a[x];
			}
			if(s[i].sco>=g)
				ans++;
		}
		printf("%d\n",ans);
		sort(s,s+n,cmp);   //降序 
		for(i=0;i<ans;i++){
			cout<<s[i].na;
			printf(" %.lf\n",s[i].sco);
		}
	}
}