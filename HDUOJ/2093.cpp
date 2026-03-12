#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
#define M 100000
int a[M],c[M];
char b[M][11];
void JH(int e)
{
    
    swap(a[e],a[e+1]);
    
    swap(c[e],c[e+1]);
    /*char g[11];
    strcpy(g,b[e]);
    strcpy(b[e],b[e+1]);
    strcpy(b[e+1],g);
    */
    swap(b[e],b[e+1]);
}
int main()
{
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    int i=0,x;
    char h;
    while(scanf("%s",&b[i])!=EOF)
    {
       
        for(int j=0;j<n;j++)
        {
            scanf("%d",&x);
            //getchar();
            if(x>0)   
            {
                c[i]+=x;
                a[i]++;
                scanf("%c",&h);
                if(h=='(')
                {
                    scanf("%d",&x);
                    c[i]+=m*x;
                    scanf("%c",&h);
                }
            }
            else continue;
        }
        ++i;
    }
    for(int w=1;w<i;++w)
    {
        for(int e=0;e<i-w;e++)
        {
            if(a[e]<a[e+1])
            JH(e);
            if(a[e]==a[e+1])
            {
                if(c[e]>c[e+1])
                JH(e);
                if(c[e]==c[e+1])
                {
                    if(strcmp(b[e],b[e+1])>0)
                    JH(e);
                }
            }
        }
    }
    for(int j=0;j<i;j++)
    {
        printf("%-10s %2d %4d\n",b[j],a[j],c[j]);
    }
    return 0;
}
/*
struct student
{
    char name[10];
    int sum;
    int temp;
    int solved[13];
};
int main()
{
  int n,m;
  cin>>n>>m;
  char b[10];
  student a[1000];
  int k=0;
  while(cin>>b)
  {
      strcpy(a[k].name,b);
      a[k].sum=0;
      a[k].temp=0;
      for(int i=0;i<n;i++)
      {
          cin>>a[k].solved[i];
          if(a[k].solved[i]>0)
          {
              a[k].temp+=a[k].solved[i];
              a[k].sum++;
          }
          if(getchar()=='(')
             {
                 int x;
                 cin>>x;
                 a[k].temp+=x*m;
                 getchar();
             }
     }
      k++;
  }
     for(int i=0;i<k;i++)
     {
          for(int j=0;j<k-i-1;j++)
          if(a[j].sum<a[j+1].sum)
           {
               student b;
               b=a[j],a[j]=a[j+1],a[j+1]=b;
               if(a[j].sum==a[j+1].sum)
               {
                  if(a[j].temp>a[j+1].temp)
                     b=a[j],a[j]=a[j+1],a[j+1]=b;
                  else if(a[j].temp==a[j+1].temp)
                  {
                      if(a[j].name>a[j+1].name)
                      b=a[j],a[j]=a[j+1],a[j+1]=b;
                  }
               }
           }
        printf("%-10s %2d %4d\n",a[i].name,a[i].sum,a[i].temp);
     }
}
*/
