#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	LL m1,m2;
    string str;
    while(cin>>m1>>m2>>str)
    {
        int r1,r2,r3;
        r1=r2=r3=0;
        for(int i=0;i!=str.size();++i)
        {
            switch(str[i])
            {
                case 'A': r1=m1;break;
                case 'B': r2=m2;break;
                case 'C': m1=r3;break;
                case 'D': m2=r3;break;
                case 'E': r3=r1+r2;break;
                case 'F': r3=r1-r2;break;
            }
        }
        cout<<m1<<','<<m2<<endl;
    }
     return 0;
}