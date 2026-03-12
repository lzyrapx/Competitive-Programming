#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	char a[1010]; //数组要开大一些，写成100就会WA 
	while(cin>>a){
		int len=strlen(a);
        if(len==1&&a[0]=='0')break;
        int sum=0;
        for(int i=0;i<len;i++){
        	sum+=a[i]-'0';
        }
        sum%=9;
        if(sum==0)sum=9;
        printf("%d\n",sum);
	}
        
	return 0;
}