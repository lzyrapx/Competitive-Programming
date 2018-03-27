#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
       if(n>m) swap(n,m);
       int leveln,levelm,leftn,leftm,rightn,rightm;
       
       leveln = sqrt(n-1)+1;//计算层数
       levelm = sqrt(m-1)+1;
       
       leftn = (n- (leveln-1)*(leveln-1) +1 )/2 ;//第几左斜线
       leftm = (m- (levelm-1)*(levelm-1) +1 )/2;
       
       rightn = (leveln*leveln - n)/2+1;//第几右斜线
       rightm = (levelm*levelm - m)/2+1;
       
       int ans=(abs(leveln-levelm))+(abs(leftn-leftm))+(abs(rightn-rightm));//累加得答案
       printf("%d\n",ans);
    }
    return 0;
}