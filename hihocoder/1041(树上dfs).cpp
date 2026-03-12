#include<bits/stdc++.h>
using namespace std;
const int N=110;
int m,ok,j;
int order[N];
int flag[N][N];
bitset<N>digit[N];
vector<int>road[N];

void Check_Reach(int a, int v)  //是否能到达 
{  
    digit[a][a] = 1;  
    for(int i = 0; i < road[a].size(); i++)  
    {  
        int b = road[a][i];  
        if(b == v)  
            continue;  
        Check_Reach(b, a);  
        digit[a] |= digit[b];  //按位或 
    }  
}  
  
void dfs(int a, int v)  
{  
    if(a == order[j])  
        j++;  
    if(j == m)  //到达终点 
    {  
        ok = 1;  
        return;  
    }  
    while(j < m)  
    {  
        int p = j, c = order[j];  
        for(int i = 0; i < road[a].size(); i++)  
        {  
            int b = road[a][i];  
            if(b == v)  
                continue;  
            if(digit[b][c] && flag[a][b])  
            {  
                flag[a][b] = 0;  
                dfs(b, a);  
                break;  
            }  
        }  
        if(p == j)  
            break;  
    }  
}  

int main()
{
	int a,b,t,n;
	scanf("%d",&t);
	while(t--)
	{
		ok=j=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<N;i++)
		{
			digit[i].reset();
			road[i].clear();
		}
		scanf("%d", &n);  
        for(int i = 1; i < n; i++)  
        {  
            scanf("%d%d", &a, &b);  
            road[a].push_back(b);  
            road[b].push_back(a);  
            flag[a][b] = flag[b][a] = 1;  
        }  
        scanf("%d", &m);  
        for(int i = 0; i < m; i++)  
            scanf("%d", &order[i]);  
        Check_Reach(1, -1);  
        dfs(1, -1);  
        if(ok)  
            printf("YES\n");  
        else  
            printf("NO\n");  
	}
	return 0;
}

