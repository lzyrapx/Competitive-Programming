#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring> 
char s[1005];
int a[1005];
char * temp;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int c;
    while(gets(s))
    {
        a[0]=atoi(strtok(s,"5"));
        c=1;
        while(temp=strtok(NULL,"5"))
        {
            a[c++]=atoi(temp);
        }
        qsort(a,c,sizeof a[0],cmp);
        printf("%d",a[0]);
        for(int i=1;i<c;i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}