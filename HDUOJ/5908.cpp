#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N = 100000+20;  
int a[N],vis[N];
int solve(int k,int n)
{
	map<int ,int> map1,map2;
    for(int i=1; i<=k; i++)
        map1[a[i]]++;
    for(int i=k+1; i<=n-k+1; i+=k)
    {
        map2.clear();
        for(int j=0; j<k; j++)
        {
            int num=a[i+j];
            map2[num]++;
        }
        if(map1!=map2)
            return 0;
    }
    return 1;
}
int main()
{  
    int t,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i=1; i<=n/2; i++)
        {
            if(!vis[i] && n%i==0)//如果2成立，那么如果2的倍数m也能被n整除，则m也成立
            {
                if(solve(i,n))
                {
                    for(int j=i; j<=n/2; j+=i)
                    {
                        if(j!=n && n%j==0)
                        {
                            vis[j]=1;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
                printf("%d ",i);
        }  
		cout<<n<<endl;      
    }
    return 0; 
}   

