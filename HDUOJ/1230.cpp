#include<bits/stdc++.h>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn=150;

int isp[maxn];
int p[maxn];
void prime()//筛选素数
{
    int i,j;
    int len=0;
    isp[0]=isp[1]=1;
    for(i=2;i<maxn;i++)
        if(isp[i]==0)
    {
        p[len++]=i;
        for(j=i+i;j<maxn;j+=i)
        isp[j]=1;
    }
}
int main()
{
    int n,m,i,j,k,t;
    prime();
    int a[maxn],b[maxn];
    int lena,lenb;
    int x,y;
    char op;
    while(1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&x);
        i=0;
        a[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            a[i++]=x;
            scanf("%c",&op);
        }
        lena=i;

        scanf("%d",&x);
        i=0;
        b[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            b[i++]=x;
            scanf("%c",&op);
        }
        
        lenb=i;
        reverse(a,a+lena);
        reverse(b,b+lenb);
        if(a[0]==0&&b[0]==0&&lena==1&&lenb==1)break;
        int maxlen=max(lena,lenb);
        int sum[maxn];
        memset(sum,0,sizeof(sum));
        for(i=0,k=0;i<maxlen;i++) //累加
        {
            sum[k++]=a[i]+b[i];
        }
        int lensum=k;
        for(i=0;i<lensum+10;i++)
        {
            int cur=sum[i]%p[i]; //进位
            int mod=sum[i]/p[i];
            sum[i]=cur;
            sum[i+1]+=mod;
        }
        for(i=maxn-1;i>=0;--i)if(sum[i]!=0)break;//逆序输出
        j=i;
        printf("%d",sum[j]);
        for(i=j-1;i>=0;--i)
            printf(",%d",sum[i]);
        printf("\n");
    }
    return 0;
}