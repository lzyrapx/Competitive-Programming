/*
①考虑最大盘子 n 号盘子，移动方向为A——>C，它只能在A或者C上，如果它在B上，则为false；
②如果 n 号盘子在 A 上，则其上的 n-1 号盘子必处于从A——>B的移动过程中，此时最大盘号为 n-1，移动方向为A—>B；
③如果 n 号盘子在 C 上，则其上的 n-1 号盘子必处于从B——>C的移动过程中，此时最大盘号为 n-1，移动方向为B—>C； 
④重复①②③。
*/ 
#include<bits/stdc++.h>
#define maxn 70
using namespace std;

int a[4][maxn];
int hanno(int n,int A,int B,int C)//A通过B移到C 
{
    if(n<1)return 1;
    int s1=a[A][0];
    int s2=a[B][0];
    int s3=a[C][0];
    if(a[A][s1]==n) //A
	{
      a[A][0]--;
      return hanno(n-1,A,C,B);
    }
    if(a[C][s3]==n)//C
    {
      a[C][0]--;
      return hanno(n-1,B,A,C);
    }
    return 0;	  
}

int main()
{
	int n;
	int t;
  	scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
        scanf("%d",&a[0][0]);
        for(int i=a[0][0];i>=1;i--)scanf("%d",&a[0][i]);
        scanf("%d",&a[1][0]);
        for(int i=a[1][0];i>=1;i--)scanf("%d",&a[1][i]);
        scanf("%d",&a[2][0]);
        for(int i=a[2][0];i>=1;i--)scanf("%d",&a[2][i]);
        
        if(hanno(n,0,1,2))puts("true");
        else puts("false");
	}
  return 0;
}