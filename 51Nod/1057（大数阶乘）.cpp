#include<stdio.h>  
int a[9999]={1,0};
int n,i,c,len,j;   
int main()    
{   
    scanf("%d", &n);  
    for ( len=1,j=2;j<=n; ++j)   
    {   
        for (c=0,i=0; i<len;++i)   
        {   
            a[i]= ( c+= a[i]*j ) % 100000; 
			c/=100000;   
        }   
        if((a[i]=c)>0)++len;  
    }      
    printf("%d",a[--len]);  
    for(;len;)  
        printf("%05d", a[--len]);  
    return 0;   
}  