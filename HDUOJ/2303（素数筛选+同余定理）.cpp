题意：给你两个数s，k； 让你求s的最小素因子是否小于k。

题解：
高精度求模+同余模定理。

素数筛选要筛选打表到100W以上（题目要求10^6）。
根据同余定理， X*Y%mod==(X%mod*Y%mod)%mod
可以将K分解再取mod。

#include<bits/stdc++.h> 
using namespace std;
const int INF = 999999;
int prime[1000003],prim[333334];
char s[234];
int main()
{
   
    int k,num=0;
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=1000000; i++){
        if(prime[i]==0){
            prim[num++]=i;
            for(int j=i*2; j<=1000000; j+=i)
                prime[j]=1;
        }
    }
    while(scanf("%s %d",s,&k))
    {
        if(k==0&&s[0]=='0') break;
        int len=strlen(s);
        int sum=0,minn=10000003,i;
        for( i=0;i<num; i++)
        {
            sum=0;
            for( int j=0;j<len;j++)
                sum=(sum*10+(s[j]-'0'))%prim[i];//mod
            if(sum==0)
                break;
        }
        if(i!=num&&prim[i]<k)
        {
        	printf("BAD %d\n",prim[i]);
		}
        else printf("GOOD\n");
    }
    return 0;
}