#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>    
using namespace std;
char Map[105] [105];
int map2[105] [105];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
struct node
{
    int s[1000][5];
    int steps;
    int x,y;
};
void bfs()
{
    queue<node>q;
    node s;
    s.steps = 0;
    s.x = 0;
    s.y = 0;
    q.push(s);
    while(!q.empty())
    {
        node s1 =q.front();
        q.pop();
        int x1 =s1.x;
        int y1= s1.y;
        //已经到达终点，并且怪兽都杀死了
        if(x1==m-1&&y1==n-1&&(Map[y1][x1]=='.'||Map[y1][x1]=='0'))
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", s1.steps);
            for(int i=0; i<s1.steps; i++) 
            {
                cout<<i+1<<"s:";
                int cnt = s1.s[i][0];
                if(cnt == 2)
                {
                    printf("FIGHT AT (%d,%d)", s1.s[i][2], s1.s[i][1]);
                }
                else if(cnt == 4)
                {
                    printf("(%d,%d)->(%d,%d)", s1.s[i][2], s1.s[i][1], s1.s[i][4], s1.s[i][3]);
                }
                cout<<endl;
            }
            return ;
        }
        //该点的怪兽还未杀死，不能往下一步跳
        else if(Map[y1][x1] != '.' && Map[y1][x1] != 'X' && Map[y1][x1] != '0')
        {
                node s2 ;
                s2.x = x1;
                s2.y = y1;
                for(int i=0; i<s1.steps; i++)
                {
                    for(int j=0; j<5; j++)    
                    {
                        s2.s[i][j] = s1.s[i][j];
                    }
                }
                //把作战的两个数字传入
                s2.s[s1.steps][0] = 2;
                s2.s[s1.steps][1] = x1;
                s2.s[s1.steps][2] = y1;
                s2.steps = s1.steps + 1;
                Map[y1][x1] = Map[y1][x1] - 1;//地图上的点减小一，怪的血下降1滴
                q.push(s2);
        }
        else //可以往下一步跳    
            for(int i=0; i<4; i++)
            {
                int x2 = x1 + dir[i][0];
                int y2 = y1 + dir[i][1];
                if( x2>=0 && x2<m && y2 >=0 && y2 <n && map2[y2][x2] == 0)
                {
                        if(Map[y2][x2] == 'X') continue;//如果是陷阱，就不去了
                    else 
                    {
                        map2[y2][x2] = 1; //地图标记此点已经走过了
                        node s2 ;
                        s2.x = x2;
                        s2.y = y2;
                        for(int i1=0; i1<s1.steps; i1++)
                        {
                            for(int j1=0; j1<5; j1++)    
                        {
                            s2.s[i1][j1] = s1.s[i1][j1];
                        }
                    }
                    s2.s[s1.steps][0] = 4;
                    s2.s[s1.steps][1] = x1;
                    s2.s[s1.steps][2] = y1;
                    s2.s[s1.steps][3] = x2;
                    s2.s[s1.steps][4] = y2;
                    s2.steps = s1.steps + 1;
                    q.push(s2);
                }
            }
        }
    }
    cout<<"God please help our poor hero."<<endl;
    return;
}
int main()
{
    while(cin>>n>>m)
    {
        char c;
        memset(map2,0,sizeof(map2)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>c;
                Map[i][j]=c;    
            }
        }
        map2[0][0] =1;
        bfs();
        cout<<"FINISH"<<endl;
    }
    return 0;
}