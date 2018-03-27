#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int x,y,t,su;
    int s1[90],s2[90];
};
int n,m,sx,sy,ans,time;
char map[10][10];
int v[10][10][2];
int yi[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int k)
{
    queue<node>q;
    node st,ed;
    int vis=-1,i,j;
    if (k>ans) return ;
    st.x=sx;
    st.y=sy;
    st.t=0;
    st.su=0;
    memset(v,0,sizeof(v));
    v[sx][sy][0]=1;
    q.push(st);
    while (!q.empty())
    {
        ed=q.front();
        q.pop();
        if (ed.t>time) continue;
        if (map[ed.x][ed.y]=='E'&&ed.su) { vis=ed.t;break;}
        st.t=ed.t+1;
        st.su=ed.su;
        for (i=0;i<4;i++)
        {
            st.x=ed.x+yi[i][0];
            st.y=ed.y+yi[i][1];
            if ( st.x>=0 && st.x<n && st.y>=0 && st.y<m && map[st.x][st.y]!='#' )
            {
                if (map[st.x][st.y]=='J') st.su=1;
                else st.su=ed.su;
                if (v[st.x][st.y][st.su]) continue;
                v[st.x][st.y][st.su]=1;
                for (j=1;j<=ed.t;j++)
                {
                    st.s1[j]=ed.s1[j];
                    st.s2[j]=ed.s2[j];
                }
                st.s1[st.t]=st.x;
                st.s2[st.t]=st.y;
                q.push(st);
            }
        }
    }
    if (vis==-1)
    {
        if (ans>k) ans=k;
        return ;
    }
    for (i=1;i<=ed.t;i++)
    {
        char c=map[ed.s1[i]][ed.s2[i]];
        if (c=='S'||c=='E') continue;
        map[ed.s1[i]][ed.s2[i]]='#';
        dfs(k+1);
        map[ed.s1[i]][ed.s2[i]]=c;
    }
}
int main()
{
    int c,i,j;
    scanf("%d",&c);
    while (c--)
    {
        scanf("%d%d%d",&n,&m,&time);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf(" %c",&map[i][j]);
            if (map[i][j]=='S') { sx=i;sy=j; }
        }
        ans=4;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}