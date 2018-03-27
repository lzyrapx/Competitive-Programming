#include<iostream>
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

int main()
{
	char a[100];
    int i,max;
    while(gets(a))
    {
        max=a[0];
        for(i=0;i<strlen(a);++i)
        {
            if(max<a[i])
            {
                max=a[i];
            }
        }
        for(i=0;i<strlen(a);++i)
        {
            if(max==a[i])
            {
                cout<<a[i]<<"(max)";
            }
            else 
			   cout<<a[i];
        }
        cout<<endl;
    }
	return 0;
}