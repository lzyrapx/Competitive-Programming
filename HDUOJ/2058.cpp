#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long m ,n;
    while(cin>>n>>m,n||m)
    {
        long long  a,k;
        for(k=(int)sqrt(2*m);k>0;k--) //因为1+2+。。。+（2*m)^1/2>m;所一和为m的元素个数应该小于等于（2*m）^1/2;
        {
            a=m/k-(k-1)/2; //假设从a开始一直加到a+k-1,一共k个元素和为m,可以计算出a;
            if((2*a-1+k)*k==2*m) //（2*m)^1/2可能不是整数，判断是有必要的；
                cout<<"["<<a<<","<<k+a-1<<"]"<<endl;
        }
		cout<<endl;
    }
	return 0;
}