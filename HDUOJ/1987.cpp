#include<bits/stdc++.h>
using namespace std;

char a[28]={" ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int convert(char *s)
{   
	int sum=0;
	for(int i=0; i<5; i++)
	{
		sum *=2;
		sum += s[i]-'0';
	}
	return sum;
}

void convert_again(char *sss,int n,int m)
{
	char temp[1000]="";
	char space[2]=" ";
	char s[6];
	s[5] = '\0';
	char ss[22][22];
	char *p=sss;
	for(int i=0; i<n; i++)
	{
		strncpy(ss[i],p,m);
		ss[i][m]='\0';
		p +=m;
	}

	int b1,b2,t,tt; //b1低行，b2低列，t,高行，tt 高列；
	b1 = b2 = 0;
	t = n;
	tt = m;
	int k=0;
	int g=0;
	int tst=0;
	int begin=1;
	while(1)
	{
		if(b1>=t||b2>=tt) break;
		for(g=b2; g<tt; g++)
		{
			s[k++] = ss[b1][g];
			if(k == 5)
			{
				if(a[convert(s)]!=' ')
				{
					printf("%s",temp);
					strcpy(temp,"");
					printf("%c",a[convert(s)]);
					tst+=5;
					begin=0;
				}
				else
				{
					if(!begin)
					{
						strcat(temp,space);
					}
				}
				k=0;
			}
		}
		b1++;
		if(b1>=t||b2>=tt) break;
		for(g=b1; g<t; g++)
		{
			s[k++] = ss[g][tt-1];
			if(k == 5)
			{
				if(a[convert(s)]!=' ')
				{
					printf("%s",temp);
					strcpy(temp,"");
					printf("%c",a[convert(s)]);
					tst+=5;
					begin=0;
				}
				else
				{
					if(!begin)
					{
						strcat(temp,space);
					}
				}
				k=0;
			}
		}
		tt--;
		if(b1>=t||b2>=tt) break;
		for(g=tt-1; g>=b2; g--)
		{
			s[k++] = ss[t-1][g];
			if(k == 5)
			{
				if(a[convert(s)]!=' ')
				{
					printf("%s",temp);
					strcpy(temp,"");
					printf("%c",a[convert(s)]);
					tst+=5;
					begin=0;
				}
				else
				{
					if(!begin)
					{
						strcat(temp,space);
					}
				}
				k=0;
			}
		}
		t--;
		if(b1>=t||b2>=tt) break;
		for(g=t-1; g>=b1; g--)
		{
			s[k++] = ss[g][b2];
			if(k == 5)
			{
				if(a[convert(s)]!=' ')
				{
					printf("%s",temp);
					strcpy(temp,"");
					printf("%c",a[convert(s)]);
					tst+=5;
					begin=0;
				}
				else
				{
					if(!begin)
					{
						strcat(temp,space);
					}
				}
				k=0;
			}
		}
		b2++;
		if(b1>=t||b2>=tt) break;
	}	
}

int main()
{
	int t,r,c;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{   
		
		char s[410];
		scanf("%d%d%s",&r,&c,s);
		printf("%d ",cas++);
		convert_again(s,r,c);
		puts("");
	}
	return 0;
}