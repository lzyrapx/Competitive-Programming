#include<bits/stdc++.h> 
using namespace std;
int p[100010];
int t = 0;
//http://blog.csdn.net/acdreamers/article/details/8883285
void divide(long long n)
{
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            p[t ++] = i;
            while(n % i == 0) n /= i;
        }
    }
}

int solve(long long x,long long n,long long m)
{
    long long res = 1;
    while(n > 0){
        if(n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int main()
{
    long long a;
    cin >> a;
    divide(a - 1);//求a-1所有的质因子 
    for(int i = 2; i < a; i++)
	{
        bool flag = false;
        for(int j = 0; j < t; j++)
		{
            if(solve(i,(a - 1) / p[j], a ) == 1)//判断是否是原根 
			{
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << i << endl;
            break;
        }
    }
    return 0;
}