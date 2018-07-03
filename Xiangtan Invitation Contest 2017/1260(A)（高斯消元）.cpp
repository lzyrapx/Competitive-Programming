#include <bits/stdc++.h>
using namespace std;
const int MAXN=205;
const int mod=1000000007;
int a[MAXN][MAXN],b[MAXN][MAXN];
int q_mod(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        k>>=1;
    }
    return res;
}
void gauss(int n)
{
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		b[i][j]=(i==j);
		}
            
	}
        
    int det=1;
    for(int i=1;i<=n;i++)
    {
        int t=i;
        for(int k=i;k<=n;k++)
        {
        	if(a[k][i])t=k;
		}
            
        if(t!=i)det*=-1;
        for(int j=1;j<=n;j++)
        {
            swap(a[i][j],a[t][j]);
            swap(b[i][j],b[t][j]);
        }
        det=1LL*a[i][i]*det%mod;
        int inv=q_mod(a[i][i],mod-2);
        for(int j=1;j<=n;j++)
        {
            a[i][j]=1LL*inv*a[i][j]%mod;
            b[i][j]=1LL*inv*b[i][j]%mod;
        }
        for(int k=1;k<=n;k++)
        {
            if(k==i)continue;
            int tmp=a[k][i];
            for(int j=1;j<=n;j++)
            {
                a[k][j]=(a[k][j]-1LL*a[i][j]*tmp%mod+mod)%mod;
                b[k][j]=(b[k][j]-1LL*b[i][j]*tmp%mod+mod)%mod;
            }
        }
    }
  //  cout<<"det="<<det<<endl;
    det=(det+mod)%mod;
  //  cout<<"det="<<det<<endl;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
        {
        	b[i][j]=1LL*det*b[i][j]%mod;
		}
	}                 
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	//把矩阵补全 
        for(int j=1;j<=n;j++) a[1][j]=2;
        
        for(int i=2;i<=n;i++)
            for(int j=1;j<=n;j++){
            	scanf("%d",&a[i][j]);
			}
                
        gauss(n);
     //   for(int i=1;i<=n;i++){
     //   	for(int j=1;j<=n;j++)
     //   	{
     //   		cout<<b[i][1]<<" ";
	//		 }
	//		 cout<<endl;
	//	}
		
        for(int i=1;i<=n;i++)
        {
        	if(i&1)
        	{
        		printf("%d",b[i][1]);//逆矩阵第一列 
        		if(i==n)cout<<endl;else cout<<" ";
			}
			else
			{
				printf("%d",(mod-b[i][1])%mod);
				if(i==n)cout<<endl;else cout<<" ";
			}
		}
            
    }
    return 0;
}
