#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int maxn = 8;
int N, K;
/*
可以通过矩阵快速幂求解。
为每个正多边形（最多三个）构建一个邻接矩阵A，然后第K步的方案数即为A^k。
结果即为A^1 + A^2 + A^3 + ...... + A^k.
对于这种形式的矩阵运算，我们可以把它拆分成：
k为奇：ans = （A^1 + A^2 + ... + A^(k/2)) + (A^1 + A^2 + ... + A^(k/2)) * A^(k.2) + A^k；
k为偶：ans = （A^1 + A^2 + ... + A^(k/2)) + (A^1 + A^2 + ... + A^(k/2)) * A^(k.2)；
合并一下就是：
ans = （A^1 + A^2 + ... + A^(k/2)) * (A(k/2) + 1);
if(k & 1) ans = ans + A^k;
结果即为mat[s - 1][e - 1]（保存的时候下标均以减一）。
*/
typedef struct M
{
    ll mat[maxn][maxn];
    M operator * (const M &t) const{//重载矩阵乘法
        M tmp;
        memset(tmp.mat, 0, sizeof(tmp.mat));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
						tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k] * t.mat[k][j]) % mod;
				}
			}
		}
	
        return tmp;
    }
    
    M operator + (const M &t) const{//重载矩阵加法
        M tmp;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				tmp.mat[i][j] = (mat[i][j] + t.mat[i][j]) % mod;
			}
		 } 
		
        return tmp;
    }
}M;
M A[3] =
{
    {{//正四边形
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 0},
    }},
    {{//正六边形
    {0, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0 ,0, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0 ,1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    }},
    {{//正八边形
    {0, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 1},
    {0, 1, 1, 1, 1, 0},
    }},
}, E;
M pow(ll k)//矩阵快速幂求A^k.
{
    M res = E, tmp = A[K];
    while(k)
    {
    	if(k & 1) res = res * tmp;
    	k >>= 1;
        tmp = tmp * tmp;
	}
    return res;
}
M q_pow(ll k)//递归快速幂求A^1 + A^2 + A^3 + ...... + A^k.
{
    if(k == 1) return A[K];
    M res = q_pow(k >> 1) * (E + pow(k >> 1));
    if(k & 1) res = res + pow(k);
    return res;
}

int main()
{
    int t, n, s, e;
    ll k;
    for(int i=0;i<maxn;i++)
    {
    	for(int j=0;j<maxn;j++)
    	{
    		E.mat[i][j] = (i == j);//初始化单位矩阵
		}
	}
    scanf("%d", &t);
    while(t--)
	{
        scanf("%d%lld%d%d", &n, &k, &s, &e);
        N = (n == 4 ? 4 : (n == 6 ? 8 : 6));//选择矩阵需要的范围
        K = (n == 4 ? 0 : (n == 6 ? 1 : 2));//选择正多边形的类型
        printf("%lld\n", q_pow(k).mat[s - 1][e - 1]);
    }
    return 0;
}
