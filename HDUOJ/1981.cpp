#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int T, i, n, len, a, b, temp,j, k;
	char str[28] = "bcdefghijklmnopqrstuvwxyza", ch[2], letter[90010];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&len,&n,letter + 1);
		for(i = 0;i < n; i++)
		{
			scanf("%s",ch);
			if(ch[0] == 'Q')
			{
				scanf("%d",&a);
				printf("%c\n",letter[a]);
			}
			else if(ch[0] == 'R')
			{
				scanf("%d%d",&a,&b);
				for(j = a, k = b;j <= k; j++, k-- ){
					temp = letter[j], letter[j] = letter[k], letter[k] = temp;}
			}
			else if(ch[0] == 'S')
			{
				scanf("%d%d",&a,&b);
				for(j = a; j <= b; j++)
				{
					letter[j] = str[ letter[j] - 'a'];
				}
			}
		}
	}
	return 0;
}