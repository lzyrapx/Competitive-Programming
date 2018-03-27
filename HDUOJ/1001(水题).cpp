#include <iostream>
using namespace std;
int main()
{
   int n;
   while(cin>>n)
   {
       int sum=0;
       for(int i=1;i<=n;++i)
       {
           sum=sum+i;
       }
       cout<<sum<<endl;
        cout<<endl;
   }
   return 0;

}