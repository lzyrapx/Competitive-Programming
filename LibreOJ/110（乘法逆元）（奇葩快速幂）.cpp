#include<bits/stdc++.h>
using namespace std;
inline int mul_mod(int a,int b,int mod)
{
	int ret;
	__asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n" :"=d"(ret):"a"(a),"b"(b),"c"(mod));
	return ret;
}
inline int ksm(int x,int y,int mod)
{
	int bit=1<<25;
	int ans=1;
	while(bit)
	{
		ans=mul_mod(ans,ans,mod);
		if(y&bit)ans=mul_mod(ans,x,mod);
		bit>>=1;
	}
	return (int)ans;
}
int n,p;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		printf("%d\n",ksm(i,p-2,p));
	return 0;
}
