/*
* this code is made by LzyRapx
* Problem: 1105
* Verdict: Accepted
* Submission Date: 2017-06-21 18:28:51
* Time: 116MS
* Memory: 10588KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
char mp[1234][1234];
bool vis[1234][1234][4];
bool mark[1234][1234];
int way[5][2]= {{0,0},{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
//http://blog.csdn.net/liangzhaoyang1/article/details/73554713
void dfs(int x,int y,int dir,int &res)
{
    while(1)
    {
        if(x<0||x>=n||y<0||y>=m) break;
        if(vis[x][y][dir]) break;
        if(mp[x][y]=='*') break;
        vis[x][y][dir]=1;
         if(mp[x][y]=='E'&&!mark[x][y])
         {
            res++;
         }
         mark[x][y] = 1;
         if(dir==1)//上 
         {
            if(mp[x][y]=='/')dir=4; // 右 
            else if(mp[x][y]=='\\')dir=3;//左
             x += way[dir][0];
             y += way[dir][1]; 
         }
         else if(dir==2)//下 
        {
            if(mp[x][y]=='/') dir=3;//左 
            else if(mp[x][y]=='\\') dir=4;
            x+=way[dir][0];
            y+=way[dir][1];
        }
        else if(dir==3)//左 
        {
            if(mp[x][y]=='/') dir=2;//下 
            else if(mp[x][y]=='\\') dir=1;
            x+=way[dir][0];
            y+=way[dir][1];
        }
        else if(dir==4)//右 
        {
            if(mp[x][y]=='/') dir=1;//上 
            else if(mp[x][y]=='\\') dir=2;
            x+=way[dir][0];
            y+=way[dir][1];
        }
    }
}
int main()
{
    int x,y;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='T'){
                    x = i;
                    y = j; 
                }
            }
             
        }
        int res = 0;
        for(int i=1;i<=4;i++)
        {
            int tmp = 0;
            memset(vis,0,sizeof(vis));
            memset(mark,0,sizeof(mark));
             
            dfs(x,y,i,tmp);
             
            res = max(res,tmp);
        }
        cout<<res<<endl;
    }
    return 0;
}