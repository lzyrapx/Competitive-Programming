#include <cstdio>
#define max(a,b) a>b?a:b;
int n,m,w[505],p[505],f[100005],i,j;
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d%d",&w[i],&p[i]);
	for(i=0;i<n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+p[i]);
	printf("%d\n",f[m]);
	return 0;
}