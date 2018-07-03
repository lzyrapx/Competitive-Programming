#include <bits/stdc++.h>
using namespace std;
char s[22][22];    
int main()  
{  
    int n,m,a,b;  
    while(~scanf("%d %d %d %d",&n,&m,&a,&b))  
    {  
        for(int i=0; i<n; i++)  scanf("%s",s[i]);  
        for(int i=0; i<n*a; i++)  
        {  
            for(int j=0; j<b*m; j++)
            {
            	printf("%c",s[i/a][j/b]);
			 }      
            printf("\n");  
        }  
    }  
    return 0;  
}  