#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define L 10+1
using namespace std;

struct T{
    int num;
    T* next[26];
    T(){
        num=0;
        int i;
        for(i=0;i<26;i++)
            next[i]=NULL;
    }
}t;
void In(char str[]){
    T* p=&t;
    for(int i=0;str[i];i++){
        int a=str[i]-'a';
        if(p->next[a]==NULL)
            p->next[a]=new T;
        p=p->next[a];
        p->num++;
    }
}
int find(char str[]){
    T* p=&t;
    for(int i=0;str[i];i++){
        int a=str[i]-'a';
        if(p->next[a]==NULL)return 0;
        p=p->next[a];
    }
    return p->num;
}
int main(){
    int n,m;
    char str[L];
    scanf("%d",&n);
    while(n--){
    	scanf("%s",str), In(str);
    }
        
    scanf("%d",&m);
    while(m--){
    	 scanf("%s",str);
    	 printf("%d\n",find(str));
    }
    
    return 0;
}
