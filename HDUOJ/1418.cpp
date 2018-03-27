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
typedef long long LL;  
using namespace std; 
const int maxn=20005;
int s[maxn];
//欧拉公式:
///简单多面体的顶点数V、面数F及棱数E间有关系　
//V+F-E=2
//(此题：顶点+面数-2=棱数)
int main()
{
   LL n,m;
   while(cin>>n>>m)
   {
       if(n==0&&m==0)break;
        printf("%lld\n",n+m-2);
   }
    return 0;
}
