//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int len ;
string str;
long long odd()//子串是奇数 
{
	ll ans = 0;
	for(int i=len-2;i>0;--i)
	{
		for(int j=1;j<=min(len-i-1,i);j++)
		{
			if(str[i+j] == str[i-j])
			{
				ans++;
			}
			else break;
		}
	}
	return ans;
}
long long even()//子串是偶数 
{
	ll ans = 0;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<=min(len-i-2,i);j++)
		{
			if(str[i-j] == str[i+j+1])
			{
				ans++;
			}
			else break;
		}
	}
	return ans;
}
int main()
{
	while(cin>>str) 
	{
		len=str.size();
		printf("%I64d\n",odd()+even()+len);	
	} 
	return 0;
}