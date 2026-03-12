#include<iostream>
using namespace std;
int f(int,int);
int main()
{
	int N,Y;
	int n;
	cin>>n;	
	for(int i=0;i<n;i++)
	{
		cin>>Y>>N;
		cout<<f(Y,N)<<endl;
	}
	return 0;
}
int f(int n,int m)
{
	 int i=0;
	 while(1)
	 {
		 if((n%4==0&&n%100!=0)||n%400==0)
		 {
			 i++;
			 if(i==m)break;
			 n+=4;
		 }
		 else n++;
	 }
	 return n;
}