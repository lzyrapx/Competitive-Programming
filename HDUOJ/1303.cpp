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
int n[201];
int main()
{
	int t;
	char c;
	while(cin>>t,t+1){		
		memset(n, 0, sizeof(n));
		n[t]=1;
		while(cin>>t,t)
			n[t]=1;
			int count = 0;

		for(int i = 0; i < 200; i++)
			if(n[i])
				if(n[2 * i])
					count++;
		cout << count <<endl;
		
       }
     return 0;
}