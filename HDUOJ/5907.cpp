#include<stdio.h>
#include<string.h>
const int N = 100000+20;  
char S[N];  
int main(){  
    int t;  
    scanf("%d",&t);  
    while(t--)
	{  
        scanf("%s",S);  
        long long cnt=0,ans=0;  
        int L=strlen(S);  
        for(int i=0;i<=L;i++)
		{  
            if(S[i]=='q')
			{  
                cnt++;  
            }  
            else if(S[i]!='q'&&S[i-1]=='q')
			{  
                ans+=cnt*(cnt+1)/2;
				cnt=0; 
            }  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}   