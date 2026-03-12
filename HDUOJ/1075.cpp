#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>    
using namespace std;
int main()
{
	char buf[12], s1[12], s2[12], ch;
	map<string, string> mp;
	int id = 0;
	gets(buf); 
	while(scanf("%s%s", s1, s2), strcmp(s1, "END"))
	{
		mp[s2] = s1;
	}
	getchar();
	while(scanf("%c", &ch))
	{		
		if(isalpha(ch)) 
		   buf[id++] = ch;
		
		else
		{	
			buf[id] = '\0';
			 id = 0;
			if(strcmp(buf, "END") == 0) break;
			if(mp.find(buf) != mp.end())
			{
				cout << mp[buf]; //找到对应的就输出 
			}
			else 
			printf("%s", buf); //否则输出原字符串 
			putchar(ch);
		}
	}
	return 0;
}