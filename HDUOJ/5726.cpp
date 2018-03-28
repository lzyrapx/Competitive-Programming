#include<bits/stdc++.h>
using namespace std;  
typedef long long ll; 
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
map<int,ll>mp;  
const int N=1e5+7;  
int n,i,j,a[N],l[N],v[N],tr[N<<2];  
using namespace std;
//给你n个数（n<=1e5）然后 m个询问(m<=1e5)，每个询问一个区间
//问你这个区间的GCD是多少
//并且输出从1到n有多少个区间的GCD和这个区间的相同
void init(){  
    mp.clear();  
    scanf("%d",&n);  
    for(int i=1 ; i<=n ; i++)
		scanf("%d",a+i);  
    for(int i=1; i <= n; i++)
		for(v[i]=a[i],j=l[i]=i; j ; j=l[j]-1)
		{	  
        	v[j]=__gcd(v[j],a[i]);  
        	while(l[j] > 1 && __gcd(a[i],v[l[j]-1])==__gcd(a[i],v[j]))
				l[j] = l[l[j] - 1];  
        	mp[v[j]] += j - l[j] + 1;  
    	}  
}  
void build(int l=1,int r=n,int rt=1)
{  
    if(l==r){
		tr[rt]=a[l];
		return;
	}  
    int m=(l+r)>>1;  
    build(lson);
	build(rson); 
    tr[rt]=__gcd( tr[rt<<1] , tr[rt<<1|1]);  
}  

int query(int L,int R,int l=1,int r=n,int rt=1)
{  
	
    if(L<=l&&r<=R)	return tr[rt];  
    int m=(l+r)>>1;  
    if(R<=m)	return query(L,R,lson);  
    if(L>m) 	return query(L,R,rson);  
    return __gcd(query(L,R,lson) , query(L,R,rson));  
}  
int main()
{
	int t;
	int x,y,k;
	int cas= 1;
	scanf("%d",&t);
	while(t--)
	{
		init();
		build();
		scanf("%d",&k);
		printf("Case #%d:\n",cas++);
		while(k--)
		{
			scanf("%d%d",&x,&y);
			int ans = query(x,y);
			printf("%d %lld\n",ans,mp[ans]);
		}
	}
	return 0;
}