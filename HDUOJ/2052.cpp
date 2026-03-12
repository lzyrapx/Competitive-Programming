#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int i,j;
		cout<<"+";
		for(i=1;i<=n;i++)
		cout<<"-";
		cout<<"+"<<endl;
		for(i=1;i<=m;i++){
			cout<<"|";
			for(j=1;j<=n;j++)
			cout<<" ";
			cout<<"|"<<endl;
		}
		cout<<"+";
		for(i=1;i<=n;i++)
		cout<<"-";
		cout<<"+"<<endl;
		cout<<endl;
	}
	return 0;
}