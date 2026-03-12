#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int num = 0;
		int sum = 0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!='?'&& s[i]!='X')
			{
				sum += (10-i)*(s[i]-'0');
			}
			else if(s[i]=='X')
			{
				sum += 10;
			}
			else if(s[i]=='?')
			{
				num = 10-i;//小标，权值 
			}
		}
		int i;
		for(i=0;i<=10;i++)
		{
			if((sum+num*i)%11==0)break;
		}
		if(i==10)
		{
			if(num!=1)cout<<"-1"<<endl;
			else puts("X");
		}
		else cout<<i<<endl;
	}
	return 0;
} 