#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
struct stud
{
    int num;
    char name[10];
    int score;
} stu[100001];
int cmp1(stud a,stud b)
{
    return a.num<b.num;
}
int cmp2(stud a,stud b)
{
    if(strcmp(a.name,b.name)==0)
        return a.num<b.num;
    return strcmp(a.name,b.name)<0;
}
int cmp3(stud a,stud b)
{
    if(a.score==b.score)
        return a.num<b.num;
    return a.score<b.score;
}
int main()
{
    int n,c,cas=1;
    while((cin>>n>>c)&&(n||c))
    {
        memset(stu,0,sizeof(stu));
        for(int i=0; i<n; i++)
            scanf("%d %s %d",&stu[i].num,stu[i].name,&stu[i].score);
        if(c==1)
            sort(stu,stu+n,cmp1);
        else if(c==2)
            sort(stu,stu+n,cmp2);
        else if(c==3)
            sort(stu,stu+n,cmp3);
        printf("Case %d:\n",cas++);
        for(int i=0; i<n; i++)
            printf("%06d %s %d\n",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}