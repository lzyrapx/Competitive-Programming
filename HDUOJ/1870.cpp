#include<stdio.h>
int main()
{    
	
    char a[1000];
    while(~scanf("%s",&a))
	{
		int n=0;
    	for(int i=0; ;i++)
    	{    
			if(a[i]==')') n--;
        	if(a[i]=='(') n++;
        	if(a[i]=='B') break;
		}
    	printf("%d\n",n);
	}
	return 0;
}