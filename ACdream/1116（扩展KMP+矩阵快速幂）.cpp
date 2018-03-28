#include<cstdio>
#include<cstring>
#include<iostream>
//using namespace std;
const int mod = 1e9+7;
struct matrix
{
	long long factor[2][2];
}M;
matrix multi(matrix x,matrix y)
{
    matrix temp;
    temp.factor[0][0] = (x.factor[0][0] * y.factor[0][0] + x.factor[0][1] * y.factor[1][0]) % 1000000007;
    temp.factor[0][1] = (x.factor[0][0] * y.factor[0][1] + x.factor[0][1] * y.factor[1][1]) % 1000000007;
    temp.factor[1][0] = (x.factor[1][0] * y.factor[0][0] + x.factor[1][1] * y.factor[1][0]) % 1000000007;
    temp.factor[1][1] = (x.factor[1][0] * y.factor[0][1] + x.factor[1][1] * y.factor[1][1]) % 1000000007;
    return temp;
}
matrix qpower(int n)
{
	if(n == 1)return M;
	matrix tmp = qpower(n>>1);
	if(n&1){
		return multi(multi(tmp,tmp),M);
	}
	else return multi(tmp,tmp);
}
int fib(int num)
{
	M.factor[0][0] = 0;
	M.factor[0][1] = 1;
	M.factor[1][0] = 1;
	M.factor[1][1] = 1;
	
	int n = num -1;
	if(n > 0){
		matrix tmp =qpower(n);
		return tmp.factor[1][1];
	}
	else if(n == -1)return 0;
	else if(n == 0) return 1;
}
int min(int a,int b)
{
	return a > b ? b : a; 
}
int next[100007];

void ex_kmp(char *t,int len)
{
	next[0] = len - 1; 
	int j = 0;
	while( 1 + j < len && t[j] == t[1 + j]) j++;
	next[1] =  j - 1;
	int id = 1;
	for(int i = 2;i < len; i++)
	{
		int p = next[id] + id;
		int l = next [i - id];
		if(p < i)next[i] = -1;
		else next[i] = min(l, p - i);
		while(next[i] + i + 1 < len && t[next[i] + i + 1]== t[next[i] + 1]){
			next[i] ++;
		}
		if(i+next[i] > id + next[id]){
			id  = i;
		}
	 } 
}
char T[100010];
int main(){
	
	while(~scanf("%s",T))
	{
		int len = strlen(T);
		ex_kmp(T,len);
		
	//	for(int i=0;i<5;i++)std::cout<<next[i]<<" ";std::cout<<std::endl;
	
		int sum = 0,ans = 0;
		for(int i=len-1;i>=0;--i)
		{
			sum += next[i] + 1;
			ans = (ans + fib(sum))%mod;
			
		//	std::cout<<"ans="<<ans<<std::endl; 
		}
		printf("%d\n",ans); 
	}
	return 0;
} 