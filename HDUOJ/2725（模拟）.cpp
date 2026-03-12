#include<bits/stdc++.h>
using namespace std;
//题意：给一个字符串表示一条河。'.'表示水，其它字符表示障碍。
//人在岸上用石子打水漂，每次可以选择一个击中的距离和跳跃间隔。石子多次跳跃后击中障碍物或越过河则结束。
//每种打水漂的方案按跳跃次数（大者优）、最后在河中的距离（大者优）、
//起始位置（大者优）、跳跃间隔（小者优）比较，问最好的方案是哪种。

char s[50];
int len;

struct Node
{
    int s,d;
    int c,l;
    bool cmp(Node u)
    {
        if(u.c!=c) return u.c>c;//跳跃次数
        if(u.l!=l) return u.l>l;//在河中的距离
        if(u.s!=s) return u.s>s;//起始位置
        return u.d<d;//跳跃间隔
    }
    void Update(Node u)
    {
        if(cmp(u)) *this=u;
    }
};
Node ans;

Node calc(int s1,int d1)
{
    Node res;
    int c=0;
    while(true)
    {
        if(s1<len&&s[s1]=='.')
        {
            s1+=d1;
            c++;
        }
        else break;
    }
    res.c=c;
    if(s1>=len) s1=len-1;
    res.l=s1;
    return res;
}

int main()
{
    while(~scanf("%s",s))
    {
        if(strcmp(s,"END")==0) break;
    	ans.c=0;//跳跃次数
		ans.l=0;//在河中的距离
    	ans.s=0;//起始位置
		ans.d=len-1;//跳跃间隔,，初始化为一次跳过 
    	len=strlen(s);
    	Node tmp;
    	for(int i=0;i<len;i++)//枚举起始位置 
   		{
      	  	for(int j=1;i+j<=len;j++)//枚举跳跃间隔 
        	{
            	tmp=calc(i,j);
            	tmp.s=i;
				tmp.d=j;
            	ans.Update(tmp);
        	}
    	}
    	//输出起始位置和跳跃间隔 
    	printf("%d %d\n",ans.s,ans.d);
    }
	return 0;
}