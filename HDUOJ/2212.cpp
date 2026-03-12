#include<iostream>
using namespace std;
int f(int n){
	int i,k=1;
	for(i=1;i<=n;i++)
	k*=i;
	return k;
} 
int main()
{
	int i,a,b,s;
	for(i=1;i<50000;i++){
		a=i;
		s=0;
		while(a!=0){
			b=a%10;
			s+=f(b);
			a/=10;
		}
		if(s==i)
		cout<<i<<endl;
	}
}