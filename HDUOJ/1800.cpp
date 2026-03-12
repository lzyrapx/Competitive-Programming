#include<iostream>
#include<memory.h>
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
#define maxn 7003
int Hash[maxn],Count[maxn],n;
int maxit;
inline int ELFhash(char*key)  //字符串hash 
{
	unsigned long h=0;
	unsigned long g;
	while(*key)
	{
		h=(h<<4)+*key++;
		g=h&0xf0000000L;
		if(g)
		h^=g>>24;
		h&=~g; 
	}
	return h;
}
inline void Hashit(char *s)
{
	int k;
	while(*s=='0')
	{
		s++;
	}
	k=ELFhash(s);
	int t=k%maxn;
	while(Hash[t]!=k&&Hash[t]!=-1)
	{
		t=(t+10)%maxn;               //开放地址法解决冲突 
	}
	if(Hash[t]==-1)
	{
		Count[t]=1; Hash[t]=k;
	} 
	else if(++Count[t]>maxit)
	 maxit=Count[t];
	 return;
}
int main()  
{  
    char str[100];
    while(~scanf("%d",&n))
    {
    	memset(Hash,-1,sizeof(Hash));
    	getchar();
    	maxit=1;
    	for(int i=0;i<n;i++)
    	{
    		gets(str);
    		Hashit(str);
    	}
    	cout<<maxit<<endl;
    }
    return 0;  
}   