#include<iostream>  
#include<memory.h>  
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=3000;

int main()
{
    LL a,b,c;
    while(cin>>a>>b>>c)
    {
    	if((a+b)==c||(a+c)==b||(b+c)==a)//加 和减 
				cout<<"oh,lucky!"<<endl;
				else if((a*b)==c||(a*c)==b||(b*c)==a)//乘和除 
				cout<<"oh,lucky!"<<endl;
				//整除，注意计算机的除法不一样，会省去小数 
				else if((b&&(a%b==c||c%b==a))||(c&&(a%c==b||b%c==a))||(a&&(b%a==c||c%a==b)))
				cout<<"oh,lucky!"<<endl;
				else
				cout<<"what a pity!"<<endl;
    }
    return 0;
}
