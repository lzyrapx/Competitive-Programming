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
    int n;
	char s[100];
	while(~scanf("%d",&n))
	{
		getchar();
		while(n--)
		{
			gets(s);
			int m=strlen(s),flag=1;
			for(int i=0,j=m-1;i<m;i++,j--)
			if(s[i]!=s[j])
			{
				printf("no\n");
				flag=0;
				break;
			}
			if(flag)
			printf("yes\n");
		}
	}
    return 0;
}

-----------------

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
    int test;
    string s;
    cin >> test;
    while(test--)
    {
        cin >> s;
        int flag = 0;
        for(int i = 0;i <= s.length() / 2;i++)
        {
            if(s[i] != s[s.length() -1 - i])
            {
                flag = 1;
                break;
            }
        }
        if(flag) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;

}