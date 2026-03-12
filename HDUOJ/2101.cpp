#include <iostream>
using namespace std;
int main()
{
	int a, b;
	while(cin >> a >> b)
		cout << (((a+b) % 86) ? "no" : "yes" ) << endl;  	
	
	return 0;
}