#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T,n,m,flag=0,result;
    cin>>T;
    while(T--){
        flag=0;
        while(cin>>n>>m){
            if(m==0&&n==0) break;
            else{
                flag++;
                result=0;
                for(int a=1;a<n;a++)
                    for(int b=a+1;a<b&&b<n;b++){
                        int r1=a*a+b*b+m;
                        int r2=a*b;
                        if(r1%r2==0) result++;
                    }
                cout<<"Case "<<flag<<": "<<result<<endl;
            }
        }
       if(T!=0) cout<<endl;
    }
    return 0;
}