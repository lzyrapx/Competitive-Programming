#include <bits/stdc++.h>
#define N 1234
using namespace std;
typedef long long ll;
ll a[N],b[N],c[2*N];
int n;
ll gauss(ll matrix[1234],ll n)//计算秩 
{
    ll rank = 1;
    for(int i = 1;i <= 100;i++) //第i个方程 
    {
        ll t = rank;
        while(t < n && !(matrix[t] & (1LL<<(i-1)))) 
		{
			t++;
		}
        if(t > n || !(matrix[t] & (1LL<<(i-1)))) continue;
        //将 rank行和 t行进行 行变换（初等行变换）
        swap(matrix[t],matrix[rank]);
        //如果方程有多个解，则二进制枚举自由变元O(2^n)，返回最小变化个数
        for(int j = rank + 1; j <= n;j++) //第j个变量 
        {
        	if((matrix[j] & (1LL<<(i-1)))) matrix[j] ^= matrix[rank];///每找到一个未知数就对其进行异或处理，去掉系数matrix[rank] 
		}     
        rank++;
    }
   // 可解出的方程组共 r 个，由秩的定义可知 r等矩阵A的秩
   //因为初始化为 1 ,所以再减去一 
    return rank-1;//秩 
}

int main()
{
    while(~scanf("%I64d",&n))
    {
    	if(n==0){
    		puts("0");continue;
		}
        for(int i = 1;i <= n;i++)
        {
            scanf("%I64d",&a[i]);
            c[i] = a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            scanf("%I64d",&b[i]);
            c[n+i] = b[i];
        } 
        int A = gauss(a,n);
      //  cout<<A<<endl; 
		int B = gauss(b,n);
	//	cout<<B<<endl;
		int C = gauss(c,2*n);
	//	cout<<C<<endl;
		printf("%I64d\n",1LL<<(A+B-C));
    }
    return 0;
}
