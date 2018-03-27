#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int flag=0;
int map[26][26];
void dfs(int x)
{
	//当 x =12，即上一个字符串的尾是 m 时，x=12代表的是m 
    if(x == 12){   
         flag= 1;
         return;
    }
    for(int i = 0; i < 26; i++)
         if(map[x][i]==1)
		 {
              map[x][i] = 0; //这个字符串已经搜过 
              dfs(i);  //继续搜以 i 为头的字符串 
              map[x][i] = 1;
         }
}

int main()
{
	char s[11];	
	while(cin>>s)
	{
		flag=0;
		memset(map,0,sizeof(map));
		int x=s[0]-'a';  
		int y=s[strlen(s)-1]-'a'; 
		map[x][y]=1;
		while(cin>>s && s[0]!='0')
		{
			  x=s[0]-'a';   
	          y=s[strlen(s)-1]-'a'; 
	          map[x][y] = 1;
		}
		dfs(1);  //从 b开始，0->a, 1->b 
		if(flag==1) puts("Yes.");
		else  puts("No.");
		}
	return 0;
}
----------------------
#include<stdio.h>
#include<string.h>
int fa[27];
void init()
{
	for(int i=0;i<27;i++)
		fa[i]=i;
}

int find()
{
	int t='m'-'a';
	while(fa[t]!=t)
	{
		if(fa[t]=='b'-'a')
			return 1;
		t=fa[t];
	}
	return 0;
}

int main()
{
	char s[100];
	while(scanf("%s",s)!=EOF)
	{
		init();
		int l=strlen(s);
		if(s[0]!=s[l-1])
			fa[s[l-1]-'a']=s[0]-'a';
		while(scanf("%s",s)!=EOF&&strcmp(s,"0")!=0)
		{
			l=strlen(s);
			if(s[0]!=s[l-1])
				fa[s[l-1]-'a']=s[0]-'a';
		}
		if(find())
			puts("Yes.");
		else
			puts("No.");
	}
	return 0;
}
--------------------
