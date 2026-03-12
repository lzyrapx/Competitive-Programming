#include<iostream>     
#include<cstdlib>    
#include<cstdio>    
#include<cmath>    
#include<cstring>    
#include<string>    
#include<cstdlib>    
#include<iomanip>    
#include<vector>    
#include<list>    
#include<map>    
#include<queue>  
#include<algorithm>    
using namespace std;

int x[20001],y[20001],s[20001];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m,a,b,c,d;
    cin>>m>>n;
    memset(s,0,sizeof(s));
    for(int i=0; i<m; i++)
        cin>>x[i]>>y[i];
    for(int j=0; j<n; j++)
    {
        cin>>a>>b>>c>>d;
        for(int i=0; i<m; i++)
            if(x[i]>=a&&x[i]<=c&&y[i]>=b&&y[i]<=d)
                if(s[i]==0)// ¸²¸ÇÎÊÌâ¡£¡£¿Óµã 
                    s[i]=(c-a+d-b)*2;
    }
    sort(s,s+m,cmp);
    for(int i=0; i<m; i++)
        cout<<s[i]<<endl;
    return 0;
}