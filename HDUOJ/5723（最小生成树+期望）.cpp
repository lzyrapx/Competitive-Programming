using namespace std;
const int N =3e6;
#define LL long long
int head[N],num,cnt,sz[N],flag[N];
double ans;
struct node
{
    int st,ed,len;
}E[3*N];
struct node1
{
    int nxt,ed,len;
}EE[3*N];
void adde(int x,int y,int d)
{
    EE[cnt].ed=y;
    EE[cnt].len=d;
    EE[cnt].nxt=head[x];
    head[x]=cnt++;
}
void add(int x,int y,int d)
{
    E[num].st=x;
    E[num].ed=y;
    E[num++].len=d;
}
bool cmp(node a,node b)
{
    return a.len<b.len;
}
int fa[N];
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void dfs(int x)
{
    sz[x]=1;
    for(int i=head[x];~i;i=EE[i].nxt){
        int ed=EE[i].ed;
        if(sz[ed]==0){
            dfs(ed);
            sz[x]+=sz[ed];
        }
    }
}
void init()
{
    num=0;
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(sz,0,sizeof(sz));
    memset(flag,0,sizeof(flag));
}
void dfs1(int x,int n)
{
    flag[x]=1;
    for(int i=head[x];~i;i=EE[i].nxt){
        int ed=EE[i].ed;
        if(!flag[ed]){
            ans+=double(EE[i].len)*(n-sz[ed])*(sz[ed]);
            dfs1(ed,n);
        }
    }
}
int main()
{
    int T,n,m,x,y,z;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if(n==1&&m==0){
            printf("0 0.00\n");
            continue;
        }
        init();
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
        }
        sort(E,E+num,cmp);
        for(int i=1;i<=n;i++) fa[i]=i;
        LL lenn=0;
        for(int i=0;i<num;i++){
            int st=E[i].st,ed=E[i].ed;
            int xx=Find(st),yy=Find(ed);
            if(xx!=yy){
                lenn+=E[i].len;
                fa[xx]=yy;
                adde(st,ed,E[i].len);
                adde(ed,st,E[i].len);
            }
        }
       
        dfs(1);
        ans=0;
        dfs1(1,n);
        double t=(double)n*(n-1)/2;
        ans=ans/t;
        printf("%I64d %.2f\n",lenn,ans);
    }
    return 0;
}