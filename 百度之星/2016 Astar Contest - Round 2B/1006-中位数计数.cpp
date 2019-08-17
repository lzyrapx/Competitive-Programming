#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=20005,B=8002;

int n,a[N],s[N];

int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int Now=0,Ans=0;
            s[B+Now]++;
            for(int j=i-1;j>=1;j--)
            {
                if(a[j]>a[i])
                    Now++;
                else
                    Now--;
                s[B+Now]++;
            }
            Now=0;Ans+=s[B+Now];
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]>a[i])
                    Now--;
                else
                    Now++;
                Ans+=s[B+Now];
            }
            printf("%d",Ans);
            if(i!=n)
                putchar(' ');
            for(int j=0;j<=i;j++)
                s[B+j]=s[B-j]=0;
        }
        puts("");
    }
    return 0;
}