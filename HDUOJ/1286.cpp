#include <iostream>
using namespace std;
int main()
{
    int t;
	cin>>t;
   	 while(t--)
     {
      	int n;
      	cin>>n;
      int a[n];
      for(int i=1;i<n;i++)
         a[i]=1;
      for (int i=2;i<=n/2;i++)
      {
        if (n%i==0)
        {
        	for (int j=1;i*j<n;j++)
             a[i*j]=0;
		}
      }
      int sum=0;
      for (int i=1;i<n;i++) sum+=a[i];
      cout<<sum<<endl;
      }
     return 0; 
}