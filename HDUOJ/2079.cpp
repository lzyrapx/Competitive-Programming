#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
int c1[MAX];
int c2[MAX];
int g[MAX];
int n;

int main()
{
	int i,j,t,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(g,0,sizeof(g));
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&a,&b);
            g[a]=b;
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0;i<=41&&i<=g[1];i++) c1[i]=1;
        for(i=2;i<=8;i++)//第i个表达式 
        {
            for(j=0;j<=40;j++)//表示前面i个表达式累乘后的表达式里第j个变量
            {
                for(int k=0,s=0;j+k<=40&&s<=g[i];k+=i,s++)
                {
                    c2[j+k]+=c1[j];
                }
            }
            for(j=0;j<=40;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
	return 0;
}