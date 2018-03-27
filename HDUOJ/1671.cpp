#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL; 

using namespace std;
struct node
{
    bool end;   
    int a[10];
};

bool x;
int ptr;
node list[100000];

void Init()
{
    x=true;
    ptr=0; 
    for(int i=0;i<100000;i++)
    {
        list[i].end=false;   
        for(int j=0;j<10;j++)
            list[i].a[j]=-1;
    }
}

void Insert(char*s)
{
    bool z=false; 
    bool y=false;
    int now=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(list[now].a[s[i]-'0']==-1)
        {   
            z=true;                      
            list[now].a[s[i]-'0']=++ptr;
            now=ptr;
        }           
        else
        {
            now=list[now].a[s[i]-'0'];
            if(list[now].end) y=true;
        }
    }
    list[now].end=true;
    x=(!y)&&z;                                       
}
               
int main()
{
    int t,n;
    char s[11];
    scanf("%d",&t);
    while(t--)
    {
        Init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",&s);
            if(x) Insert(s);
        }
        if(x) puts("YES");
        else puts("NO");
    }                        
    return 0;
}