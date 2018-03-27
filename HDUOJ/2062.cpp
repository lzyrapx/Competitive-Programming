#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int a;
    long long b;
    long long g[30];
    g[1]=1;
    g[2]=2;
    for(int i=3;i<22;i++)
    {
        g[i]=g[i-1]*(i-1)+1;//求出g；
    }
    
    int num[30];
    while(scanf("%d%I64d",&a,&b)!=EOF) 
    {
        memset(num,0,sizeof(num));
        for(int i=1;i<=a;i++)
            num[i]=i;    //将要输出的数字保存在数组里
        int A=a;
        while(a--)//总共有a个数
        {
            int n=b%g[a+1]? b/g[a+1]+1: b/g[a+1];  //用b取余对应的b/g，得到要输出的数在第几组
            //cout<<endl<<"n="<<n<<endl;
            if(num[n]==0)
                break;
                
          //输出对应的组代表的数字
            if(A-1==a)
            printf("%d",num[n]);       
            else
            printf(" %d",num[n]);
            for(int i=n;i<=a;i++)
                num[i]=num[i+1];            //将刚输出的数字删掉，留下剩下的数字，没用的数字都变成0了
            //b表示在剩余子集中位于第几个,减去(n-1组总子集数+1)
            b=(b-(g[a+1]*(n-1)+1));   
            //cout<<endl<<"b="<<b<<endl;
        }
        printf("\n");
    }
    return 0;
}



/*
n=2时： 
子序列从小到大
{1},
{1, 2},
{2},
{2, 1}
n=3时： 
子序列从小到大
{1}
{1, 2}
{1, 2, 3}
{1, 3}
{1, 3, 2}
{2}
{2, 1}
{2, 1, 3}
{2, 3}
{2, 3, 1}
{3}
{3, 1}
{3, 1, 2}
{3, 2}
{3, 2, 1}
不难发现，An可以按首数字分成n组，而每组里除了第一项，剩下的就是An-1的子集合了。
∴f(n) = n[f(n-1) + 1]

f(1) = 1
 
先求的An中每一组的个数g(n)
不难得出:g(n) = f(n) / n
∵f(n) = n[f(n-1) + 1]
∴g(n) = n[f(n-1) + 1] / n = f(n-1) + 1
∵f(n-1) = (n-1) * g(n-1)
∴g(n) = (n-1) * g(n-1) + 1
*/ 
