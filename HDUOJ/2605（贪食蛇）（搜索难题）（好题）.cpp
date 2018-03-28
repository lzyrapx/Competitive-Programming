#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
//const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("runtime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
#define Wall -999
struct Snake
{
    int x,y,tep;
    int body;
    int st;
};
char Hash[20][20][30000][129];
int cas = 1;
int key[8];
bool order[8][8];
bool visit[8];
queue <Snake> q;

int n,m,L,K,R,N;
int maze[21][21];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

int cal_dir(int a,int b,int c,int d)//(a,b)在(c,d)的上下左右
{
    if(b == d)
	{
        if(a < c)
		{
            return 0;
        } 
		else
		{
            return 1;
        }
    }
	else 
	{
        if(b < d)
		{
            return 2;
        } 
		else 
		{
            return 3;
        }
    }
}
bool dfs(int idx)
{
    for(int i = 0 ; i < K ;i ++)
	{
        if(order[idx][i])
		{
            if(visit[i])
			{
                return true;
            }
            visit[i] = true;
            
            if(dfs(i))
			{
                return true;
            }
            visit[i] = false;
        }
    }
    return false;
}
bool illegal(Snake node)
{
    if(node.x < 0 || node.x == n || node.y < 0 || node.y == m || maze[node.x][node.y] == Wall)//越界|撞墙
	{
        return true;
    }
    int idx = maze[node.x][node.y];
    if(idx >= 0 && (node.st & (1<<idx)) == 0) //豆 
	{
        if((node.st & key[idx]) == key[idx])
		{
            return false;
        } 
		else //不能吃 
		{
            return true;
        }
    }
    
    //碰到了自己 
    int x = node.x;
    int y = node.y;
    int body = node.body;
    for(int i = L*2-2;i >= 0;i -= 2)
	{
        int buf = body / (1 << i);
        body %= (1<<i);
        switch(buf)
		{
            case 0:x--;break;
            case 1:x++;break;
            case 2:y--;break;
            case 3:y++;break;
        }
        if(x == node.x && y == node.y)
		{
            return true;
        }
    }
    return false;
}
int bfs()
{
    while(!q.empty())
	{
        Snake now = q.front();
        q.pop();
        if(now.x == 2 && now.y == 0)
		{
            now.x = 2;
        }
        for(int i = 0 ; i < 4 ; i ++)
		{
            Snake next = now;
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.body += (i<<(L*2-2));
            if(illegal(next))
			{
                continue;
            }
            next.body /= 4;//最后一段不要
            next.tep ++;
            int idx = maze[next.x][next.y];
            if(idx >= 0 && (next.st & (1<<idx)) == 0)
			{
                next.st += (1<<idx);
                if(next.st == ((1<<K)-1))
				{
                    return next.tep;
                }
            }
            if(Hash[next.x][next.y][next.body][next.st] == cas)
			{
                continue;
            }
            Hash[next.x][next.y][next.body][next.st] = cas;
         // printf("(%d,%d)->(%d,%d) %d\n",now.x,now.y,next.x,next.y,next.tep);
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        while(!q.empty())
		{
            q.pop();
        }
        scanf("%d%d",&n,&m);
        scanf("%d%d",&L,&K);
        scanf("%d%d",&R,&N);
        
        Snake node;
        node.body = 0;
        
        int x,y,prex,prey;
        for(int i = 0 ; i < L ; i ++)//蛇身 
		{
            scanf("%d%d",&x,&y);
            x --,y --;
            if(i == 0)
			{
                node.x = prex = x;
                node.y = prey = y;
            }
			else
			{
                node.body = node.body * 4 + cal_dir(x,y,prex,prey);
                prex = x;
                prey = y;
            }
        }
    
        memset(maze,-1,sizeof(maze));
        
        for(int i = 0 ; i < K ; i ++)//豆的位置 
		{
            scanf("%d%d",&x,&y);
            x --,y --;
            maze[x][y] = i;
        }
        memset(key,0,sizeof(key));
        memset(order,false,sizeof(order));
        
        for(int i = 0 ; i < R; i++ )//豆的关系 
		{
            scanf("%d%d",&x,&y);//先吃 x 才能吃 y 
            x --, y --;
            key[y] += (1<<x);
            order[y][x] = true;
        }
        for(int i = 0; i < N ; i++)//墙的位置 
		{
            scanf("%d%d",&x,&y);
            x --,y --;
            maze[x][y] = Wall;
        }
        if(K == 0)
		{
            puts("0");
            continue;
        }
        //判断豆子是否成环
        memset(visit,false,sizeof(visit));
        int i;
        for(i = 0 ; i < K ; i ++)
		{
            visit[i] = true;
            if(dfs(i))
			{
                break;
            }
            visit[i] = false;
        }
        //cout<<"i="<<i<<endl;
        //cout<<"k="<<K<<endl;
        if(i!=K)
		{
            puts("-1");
        } 
		else
		{
            node.st = 0;
            node.tep = 0;
            q.push(node);
            int ans = bfs(); 
            printf("%d\n",ans);
        }
        cas++;
    }
    return 0;
}
