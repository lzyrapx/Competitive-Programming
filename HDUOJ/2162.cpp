#include<iostream>   
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
const int maxn=100;

int main()
{
	int n,k=1;
    while((cin>>n)&&n>0)
    {
        int sum=0,x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }
        cout<<"Sum of #"<<k++<<" is "<<sum<<endl;
    }

}