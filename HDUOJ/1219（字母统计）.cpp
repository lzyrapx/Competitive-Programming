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
	char c[100005];
    while(gets(c)){
        int b[27]={0};
		int k=strlen(c);
        for(int i=0;i<k;i++)
            if(c[i]>='a'&&c[i]<='z')
                b[c[i]-'a']++;
        for(int i=0;i<26;i++)
            printf("%c:%d\n",i+'a',b[i]);
        puts("");
    }

	return 0;
}
