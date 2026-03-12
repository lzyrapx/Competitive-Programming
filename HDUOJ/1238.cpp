#include<iostream>
#include<stdio.h >
#include<string>
#include<algorithm>
using namespace std;
string a[110];
int main()
{
	string s1,s2;
	int t,n,i,j,mini,min,k,max;
	cin>>t;
	while(t--)
	{
		max = 0; min = 200;
		cin>>n;
		for(i=0; i<n; i++)
		{
			cin>>a[i];
			if(a[i].size() < min)
			{
				min = a[i].size();
				mini = i;
			}
		}
		for(i=0; i<a[mini].size(); i++)
		{
			for(j=1; j<=a[mini].size() - i; j++)
			{
				s1 = a[mini].substr(i,j); //返回从i开始的 j 个字符组成的字符串
				s2 = s1;
				reverse(s2.begin(),s2.end());
				for(k=0; k<n; k++)
				{
					//从0开始查找字符串s1，s2 在当前串中的位置，查找成功时返回所在位置，失败返回string::npos的值
					if(a[k].find(s1,0) == string::npos && a[k].find(s2,0) == string::npos)  
						break;
				}
				
				if(k == n && j > max)
					max = j;
			}
		}
		
		cout<<max<<endl;
	}
	return 0;
}


-------------------------
#include <iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
string str[110]; 
int t;
int cmp(const string& a, const string& b){
	return a.length()<b.length();
}
//string substr(int pos = 0,int n = npos) const;  返回从pos开始的n个字符组成的字符串

int dfs(string now,string reve,int len)
{
	for(int i=1;i<t;i++)
	{
		int sign=0;
		for(int j=0;j+len<=str[i].length();j++)
		{
			string sub=str[i].substr(j,len);  //返回从j开始 ,长度为len的子串
			
			if(sub==now||sub==reve) 
			{
				sign=1;break; //找到就继续找
			}
		}
		if(!sign)
			return 0; //否则直接退出
	}
	return len;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>t;
		for(int i=0;i<t;i++)
			cin>>str[i];
		sort(str,str+t,cmp);
		int len=str[0].length();
		int max=0;
		for(int i=len;i>=1;i--)
		{
			for(int j=0;j+i<=len;j++)
			{
				string now=str[0].substr(j,i); //回从 j开始的 i个字符组成的字符串
				string reve=now;
				reverse(reve.begin(),reve.end());
				//手写的翻转字符串,与上一行效果相同 
				//for(int k=now.length()-1;k>=0;k--) 
				//	rev+=now[k];
				//cout<<rev<<endl;
				int maxn=dfs(now,reve,i);
				if(maxn>max)
					max=maxn;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}