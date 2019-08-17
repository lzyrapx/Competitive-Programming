#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define ff first
#define ss second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9+250;
LL mod=1e9+7;
const int N=100005;
char op[15],s[45];
map<string,int> mp;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	while(n--){
	    scanf("%s%s",op,s);
	    if(op[0]=='i'){
	        string tmp=s;
	        mp[tmp]++;
        }else if(op[0]=='d'){
            string tmp=s;
	        for(map<string,int>::iterator it=mp.lower_bound(s);it!=mp.end();it++){
	            string t=it->ff;
	            if(t.find(tmp)!=0){
	                break;
                }
                it->ss=0;
            }
        }else{
            string tmp=s;
            int ok=0;
            for(map<string,int>::iterator it=mp.lower_bound(s);it!=mp.end();it++){
	            string t=it->ff;
	            if(t.find(tmp)!=0){
	                break;
                }
                if(it->ss>0){
                    ok=1;
                    break;
                }
            }
            puts(ok?"Yes":"No");
        }
    }

	return 0;
}


----------------------------------

#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
typedef long long LL;
using namespace std;
char op[32],s[32];
typedef struct node{
    int num;
    node *next[30];
    node(){
        memset(next,0,sizeof(next));
        num=0;
    }
}Trie;
void Insert(node *root,char *s){
    node *p=root;
    for(int i=0; s[i]; i++){
        int x=s[i]-'a';
        if(p->next[x]==NULL) 
		p->next[x]=new node;
        p=p->next[x];
        p->num++;
    }
}

void Delete(node *root,char *s,int cnt){
    node *p=root;
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        p=p->next[x];
        p->num-=cnt;
    }
    for(int i=0;i<30;i++)p->next[i]=0;
}
int Search(node *root,char *s){
    node *p=root;
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        if(p->next[x]==NULL) return 0;
        p=p->next[x];
    }
    return p->num;
}
int main(){
    int n;
    scanf("%d",&n);
    Trie *root=new node;
    for(int i=0;i<n;i++)
	{
        scanf("%s %s",op,s);
        if(op[0]=='i')
		{
            Insert(root,s);
        }
		else if(op[0]=='s')
		{
            int ans=Search(root,s);
            if(ans) 
			puts("Yes");
            else   
			 puts("No");
        }
		else
		{
            int cnt=Search(root,s);
            if(cnt) Delete(root,s,cnt);
        }
    }
    return 0;
}
