
#include<bits/stdc++.h>
using namespace std;
int c1[55],c2[55];
int main()
{                         //c1表示各项单词组合价值不大于50的组合的数目
    int n;                //c2表示中间量，保存每一次的情况
    int i,j,k;
    int sum;
    int a[27]={0};
    cin>>n;
    while(n--)
    {
        for(i=1;i<27;i++)
        cin>>a[i];
        memset(c2,0,sizeof(c2));
        memset(c1,0,sizeof(c1));
        for(i=0;i<51&&i<=a[1];i++) c1[i]=1;
        for(i=2;i<=26;i++)    //i表示第i个表达式
        {                     //j表示前面i个表达式累乘后的表达式里第j个变量
            for(j=0;j<51;j++)
            { 
				for(k=0;j+k<51&&k<=a[i]*i;k+=i)//关键: k表示第j个的指数 
                	c2[j+k]+=c1[j];
            }
            
            for(j=0;j<51;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        sum=0;
        for(i=1;i<=50;i++)	sum+=c1[i];
        cout<<sum<<endl;
    }
	return 0;
}