#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int x[15],num[15]={0};
int sum;
int n;
int check (int k)
{
	for(int i=1;i<k;i++)
	{
		//剪枝，即判断是否符合条件来放,i表示皇后所在的行数，x[i]表示所在的列数，
		//所以前面那个条件用来判断两个皇后是否在对角线上,后面用来判断是否在同一列上。
		//行数不需要判断，因为他们本身的i就代表的是行数
		if(abs(k-i)==abs(x[k]-x[i])||x[k]==x[i])
		return 0;
	}
	return 1;
}
void dfs(int a)
{
	if(a>n)q
	{
		sum++;
	}
	else for(int i=1;i<=n;i++)
	{
		x[a]=i; //第 a个皇后放的列数 i 
		if(check(a))  
		{
			dfs(a+1);
		}
	}
}

int main()
{ 
	int N;
	for(int i=0;i<=10;i++)
	{
		n=i; //表示几个皇后
		sum=0;  //每次都置零 
		dfs(1); //每次从第一个皇后开始 
		num[i]=sum;  //存储方案 
		
	}
	
	while(~scanf("%d",&N)&&N)
	{
		printf("%d\n",num[N]);
	}
	return 0;
}