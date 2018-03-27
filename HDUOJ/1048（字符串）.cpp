
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string start, end;
	getline(cin, start);
	while (start == "START")
	{
		string s;
		getline(cin, s);
		getline(cin, end);
		for (char &c: s)  //C++11的新特性
		{
			if (c >= 'F' && c <= 'Z')
				c -= 5;
			else if (c >= 'A' && c <= 'E')
				c += 21;
		}
		cout << s << endl;
		getline(cin, start);
	}
	return 0;
}