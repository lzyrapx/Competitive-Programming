#include <bits/stdc++.h>
using namespace std;

#define Wall -999

struct Snake
{
    int x, y, tep;   // 蛇头坐标、步数
    int body;        // 蛇身方向编码
    int st;          // 已吃豆子的状态
};

char Hash[20][20][30000][129];  // 判重数组 [x][y][body][st]
int cas = 1;                     // 测试用例编号
int key[8];                      // 豆子的前置依赖
bool order[8][8];                // 豆子依赖关系
bool visit[8];                   // DFS判环用
queue <Snake> q;

int n, m, L, K, R, N;            // 地图大小、蛇长、豆子数、依赖数、墙数
int maze[21][21];                // 地图：-1空地，0~K-1豆子，Wall墙
int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};  // 下、上、右、左

// 计算从(c,d)到(a,b)的方向
int cal_dir(int a, int b, int c, int d)
{
    if(b == d)
    {
        if(a < c) return 0;  // 下
        else return 1;       // 上
    }
    else 
    {
        if(b < d) return 2;  // 右
        else return 3;       // 左
    }
}

// DFS判断依赖关系是否有环
bool dfs(int idx)
{
    for(int i = 0; i < K; i++)
    {
        if(order[idx][i])
        {
            if(visit[i]) return true;
            visit[i] = true;
            if(dfs(i)) return true;
            visit[i] = false;
        }
    }
    return false;
}

// 判断蛇的状态是否合法（撞墙、撞自己、不能吃的豆子）
bool illegal(Snake node)
{
    // 越界或撞墙
    if(node.x < 0 || node.x >= n || node.y < 0 || node.y >= m || maze[node.x][node.y] == Wall)
    {
        return true;
    }
    
    int idx = maze[node.x][node.y];
    // 遇到豆子
    if(idx >= 0 && (node.st & (1 << idx)) == 0)
    {
        // 检查前置依赖是否已吃
        if((node.st & key[idx]) == key[idx])
        {
            return false;
        }
        else // 前置依赖没吃，不能吃这个豆子
        {
            return true;
        }
    }
    
    // 检查是否撞到自己
    int x = node.x;
    int y = node.y;
    int body = node.body;
    for(int i = L * 2 - 2; i >= 0; i -= 2)
    {
        int buf = body / (1 << i);
        body %= (1 << i);
        switch(buf)
        {
            case 0: x--; break;  // 下
            case 1: x++; break;  // 上
            case 2: y--; break;  // 右
            case 3: y++; break;  // 左
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
        
        for(int i = 0; i < 4; i++)
        {
            Snake next = now;
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.body += (i << (L * 2 - 2));  // 新方向加到最高位
            next.body /= 4;                    // 去掉最低位（蛇尾）
            
            if(illegal(next)) continue;
            
            next.tep++;
            
            int idx = maze[next.x][next.y];
            if(idx >= 0 && (next.st & (1 << idx)) == 0)  // 吃到新豆子
            {
                next.st += (1 << idx);
                if(next.st == ((1 << K) - 1))  // 所有豆子吃完
                {
                    return next.tep;
                }
            }
            
            if(Hash[next.x][next.y][next.body][next.st] == cas) continue;
            Hash[next.x][next.y][next.body][next.st] = cas;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        while(!q.empty()) q.pop();
        
        scanf("%d%d", &n, &m);
        scanf("%d%d", &L, &K);
        scanf("%d%d", &R, &N);
        
        Snake node;
        node.body = 0;
        
        int x, y, prex, prey;
        // 读入蛇身
        for(int i = 0; i < L; i++)
        {
            scanf("%d%d", &x, &y);
            x--; y--;
            if(i == 0)
            {
                node.x = prex = x;
                node.y = prey = y;
            }
            else
            {
                node.body = node.body * 4 + cal_dir(x, y, prex, prey);
                prex = x;
                prey = y;
            }
        }
    
        memset(maze, -1, sizeof(maze));
        
        // 读入豆子位置
        for(int i = 0; i < K; i++)
        {
            scanf("%d%d", &x, &y);
            x--; y--;
            maze[x][y] = i;
        }
        
        memset(key, 0, sizeof(key));
        memset(order, false, sizeof(order));
        
        // 读入豆子依赖关系
        for(int i = 0; i < R; i++)
        {
            scanf("%d%d", &x, &y);  // 先吃x才能吃y
            x--; y--;
            key[y] += (1 << x);      // y的前置依赖集合
            order[y][x] = true;      // y依赖于x
        }
        
        // 读入墙的位置
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d", &x, &y);
            x--; y--;
            maze[x][y] = Wall;
        }
        
        if(K == 0)
        {
            puts("0");
            continue;
        }
        
        // 判断豆子依赖是否有环
        memset(visit, false, sizeof(visit));
        int i;
        for(i = 0; i < K; i++)
        {
            visit[i] = true;
            if(dfs(i)) break;
            visit[i] = false;
        }
        
        if(i != K)
        {
            puts("-1");  // 有环，不可能吃完
        }
        else
        {
            node.st = 0;
            node.tep = 0;
            q.push(node);
            int ans = bfs();
            printf("%d\n", ans);
        }
        cas++;
    }
    return 0;
}