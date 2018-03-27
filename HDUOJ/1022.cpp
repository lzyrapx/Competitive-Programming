#include<bits/stdc++.h>
using namespace std;
int n;
stack<char> s;
string str1,str2,ans;
int id1,id2,flag;
int main()
{
	while(cin>>n)
	{
		flag=1;
		id1 = 0;
		id2 = 0;
		ans="";
		cin>>str1;
		cin>>str2;
		while(!s.empty())
			s.pop();
		for(int i = 0;i < n;)
		{
			if(s.empty())
			{
				s.push(str1[i++]);
				ans+="in\n";
				continue;
			}
			if(s.top()==str2[id2])
			{
				s.pop();
				id2++;
				ans+="out\n";
			}
			else
			{
				s.push(str1[i++]);
				ans+="in\n";
			}
		}
		
		if(!s.empty())
		{
			while(1)
			{
				if(s.empty())
				break;
				if(s.top()==str2[id2])
				{
					s.pop();
					id2++;
					ans+="out\n";
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<"Yes.\n"<<ans<<"FINISH"<<endl;
		else
			cout<<"No.\n"<<"FINISH"<<endl;
	}
}