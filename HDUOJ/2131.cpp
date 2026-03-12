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
#include<queue>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	char c;
    string s;

    while(cin>>c>>s)
    {
            c=tolower(c);
        int n=0;
        for(int i=0;i<s.length();i++) //s.size()Ò²¿ÉÒÔ¡£¡£¡£ 
        {
            if(tolower(s[i])==c) n++;
        }
        printf("%.5f\n",n/float(s.length()));
    }
    return 0;
}