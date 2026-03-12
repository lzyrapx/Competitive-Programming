#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm> 
using namespace std;
const int N=1e7+10;
char s[N];
int a[N];
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        int len=strlen(s);
        sort(s,s+len);
        int k=0;
        for(i=0; i<len; i++)
            if(s[i]!='0') //记录第一个不是 0 的位置 
            {
                k=i;
                break;
            }
            
        if(len==1||k==len-1)
        {
            printf("Uncertain\n");
            continue;
        }
        int j=0;
        for(i=0; i<len; i++)
            if(i!=k)
                a[j++]=s[i]-'0';
        int x=s[k]-'0';
        a[0]+=x;
        for(i=0; i<j; i++)
            if(a[i]>9)
            {
                a[i+1]++;
                a[i]%=10;
            }
            else
                break;
                
        if(a[j])
            printf("%d",a[j]);
        for(i=j-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}