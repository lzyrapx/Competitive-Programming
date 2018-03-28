//寻找循环节代码:
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main()
{
     ll a,b=1,c=0;
     for(int i=1;;i++)
     {
           a=(3*b+c)%1000000007;
           if(a==1&&b==0)
           {
                 printf("第一个循环节：%lld\n", i);
            	break;
           }
           c=b;
           b=a;
     }
     a=0,b=1,c=0;
     for(int i=1;;i++)
     {
           a=(3*b+c)%222222224;
           if(a==1&&b==0)
           {
                printf("第二个循环节：%lld\n", i);
            	break;
           }
           c=b;
           b=a;
     }
    a = 0,b=3,c=1;
	ll d = 0;
    for(int i = 2; ; i++)
    {
        a= (3 * b + c) %183120;
        if(a== 1 && b == 0)
        {
            printf("第三个循环节：%lld\n", i);
            break;
        }
        c = b;
        b = a;
    }
    return 0; 
}
