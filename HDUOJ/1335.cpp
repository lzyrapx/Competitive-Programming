#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;	
int main()
{
    char c[20];
	long int i,j,n,k,a,b,y;
	while(scanf("%s%ld%ld",c,&a,&b)!=EOF)
	{	
		char s[20];
		k=0;
		n=strlen(c);
		for(i=0;i<=n;++i)   //先转换成十进制 
		{
			if(c[i]>='0'&&c[i]<='9')
				y=c[i]-48;  //相当于 y=c[i]-'0' 
			else
				switch(c[i])
			{
				case 'A':y=10;break;
				case 'B':y=11;break;
				case 'C':y=12;break;
				case 'D':y=13;break;
				case 'E':y=14;break;
				case 'F':y=15;break;
			}
			k+=(y*(LL)pow(a,n-i-1)); 
		}
		if(k==0) {printf("      0\n");continue;}
		i=0;
		while(k)    //再转换成 b进制 
		{
			y=k%b;
			if(y>=0&&y<=9)
				s[i]=y+48;  //相当于 y=c[i]+'0' 
			else
				switch(y)
			{
				case 10:s[i]='A';break;
				case 11:s[i]='B';break;
	            case 12:s[i]='C';break;
				case 13:s[i]='D';break;
			    case 14:s[i]='E';break;
				case 15:s[i]='F';break;
			}
			k=k/b;
			i++;
		}
		if(i>7)
		printf("  ERROR");
		else
		{
			for(j=0;j<7-i;j++)
				printf(" ");
			i=i-1;
			for(;i>=0;i--)
				printf("%c",s[i]);
		}
		printf("\n");
	}
    return 0;
}