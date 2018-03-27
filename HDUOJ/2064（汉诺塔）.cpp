#include<iostream>
using namespace std;

int main()
{
	int n;
	long long step[36] = { 0,1 };
	for (int i = 2; i < 36; i++)
		step[i] = 3 * step[i - 1] + 1;
	while ((cin >> n) && n)
	{
		cout << 2 * step[n] << endl;
	}
	return 0;
}