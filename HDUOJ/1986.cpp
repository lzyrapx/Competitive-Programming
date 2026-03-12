#include<bits/stdc++.h> 
using namespace std;
const char a[27][6]={
{"00000"},{"00001"},{"00010"},{"00011"},
{"00100"},{"00101"},{"00110"},{"00111"},
{"01000"},{"01001"},{"01010"},{"01011"},
{"01100"},{"01101"},{"01110"},{"01111"},
{"10000"},{"10001"},{"10010"},{"10011"},
{"10100"},{"10101"},{"10110"},{"10111"},
{"11000"},{"11001"},{"11010"}};  
char ans[30][30];  
char num[1000];  
char s[100];  
int main()
{
	int t;
	int cas=1;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<30;i++)
		for(int j=0;j<30;j++) ans[i][j]='*';
		
		int r,c;
		scanf("%d%d",&r,&c);
		getchar();
		gets(s);
		memset(num,'\0',sizeof(num));
		int i=0;
		while(s[i]!='\0') //字母转化成数字 
		{
			if(s[i]==' ')strcat(num,a[0]);
			else
			{
				int x=s[i]-'A'+1;
				strcat(num,a[x]);
			}
			i++;
		}
		for (int i = 0; i < 400; i++)
		{  
            strcat(num, "0");  
        }  
        int tot=0;  
        int x=0,y=0;  
        ans[0][0]=num[0];  
        while(tot<r*c-1)  
        {  
        	while(y+1<c && ans[x][y+1] == '*')  //列 
            {  
                 ans[x][++y] = num[++tot];  
            }  
            
            while(x+1<r && ans[x+1][y] == '*') //行 
            {  
                ans[++x][y] = num[++tot];  
            }  
            
  			while(y-1>=0 && ans[x][y-1] == '*')  
            {  
                ans[x][--y] = num[++tot];  
            } 
            
  			while(x-1>=0 && ans[x-1][y] == '*')  
            {  
                ans[--x][y] = num[++tot];  
            } 
            
        }  
        printf("%d ",cas++);  
        for(int i=0;i<r;++i)  
            for(int j=0;j<c;++j)  
            {  
                if(ans[i][j] == '*') printf("0");  
                else printf("%c",ans[i][j]);  
            }  
        printf("\n");  
	}
	return 0;
}