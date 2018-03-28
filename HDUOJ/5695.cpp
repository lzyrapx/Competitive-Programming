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
#define MAX 100010  
int Index[MAX];  
int n, m, Count;  
int ans[MAX];  
vector<int>v[MAX];  
void TopoSort()  
{  
    priority_queue<int>Q;  
    for(int i=n; i>=1; i--)  
        if(Index[i]==0) Q.push(i);  
  
    while(!Q.empty()) 
    {  
        int tmp = Q.top();  
        Q.pop();  
        ans[Count++] = tmp;  
        for(int i=0; i<v[tmp].size(); i++)  
        {  
            Index[v[tmp][i]]--;  
            if(Index[v[tmp][i]]==0) Q.push(v[tmp][i]);  
        }  
    }  
}  
  
int main()  
{  
    int x, y,t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&m);  
          
        for(int i=0;i<=n;i++)v[i].clear(),Index[i]=0;  
        Count = 0;  
        for(int i=0; i<m; i++)  
        {  
            scanf("%d%d",&x,&y);  
            Index[y]++;  
            v[x].push_back(y);  
        }  
        TopoSort();  
        int min=1000000000;  
        long long an=0;  
        for(int i=0; i<Count; i++){ 
		   if(min>ans[i]) 
		   min=ans[i];
            an+=min;  
        }  
        printf("%I64d\n",an);  
    }  
}  