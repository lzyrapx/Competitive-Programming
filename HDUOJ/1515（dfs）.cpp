//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char x1[123],s1[123],s2[123];
char stack[123];
int len1,len2,len3;
void dfs(int x,int y,int cnt)//x是s1的位置，y是s2的位置，cnt是栈的大小 
{
	if(y==len2)//如果推出栈的长度等于s2的长度就输出 
	{
		puts("");
		for(int i=0;i<len3;i++)//输出操作步骤 
		  printf("%c ",x1[i]); 
	}
	else
	{
		if(x<len1) 
		{
			char tmp = stack[cnt];
			x1[len3++] = 'i'; //记录操作，push 
			stack[cnt] = s1[x]; //放入栈中 
			dfs(x+1,y,cnt+1);
			stack[cnt] = tmp;
			len3--;
		}
		if(cnt > 0 && stack[cnt-1]==s2[y])// 推出栈顶元素 
		{
			x1[len3++] = 'o';//记录操作 
			dfs(x,y+1,cnt-1);
			len3--;
		}
	}
}
int main()
{
	while(~scanf("%s%s",&s1,&s2))
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		if(len1!=len2)
		{
			puts("[\n]");continue;
		}
		printf("[");
		dfs(0,0,0);
		puts("\n]");
	}
	return 0;
}