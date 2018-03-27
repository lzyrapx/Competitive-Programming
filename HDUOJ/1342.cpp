#include<cstdio>
int a[20],n,v[6],size;
void dfs(int i,int num)
{
    if(i>n) return ;
    if(num==6)
	{
        for(int i=0;i<5;i++)
            printf("%d ",v[i]);
        printf("%d\n",v[5]);
        return ;
    }
    v[size++]=a[i];
    dfs(i+1,num+1);
    size--;
    dfs(i+1,num);
}
int main()
{
    int cas=0;
    while(~scanf("%d",&n),n)
	{
        size=0;
        if(cas++) puts("");
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        dfs(0,0);
    }
    return 0;
}