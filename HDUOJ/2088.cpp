#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[51];
    int mid;
    long long sum;
    bool first = true;
    while(cin >> n && n)
    {
        sum = 0;
        if(!first)
            cout << endl;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int move = 0;
        mid = sum / n;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mid)
                move += a[i] - mid;
        }
        cout << move << endl;
        first = false;
    }
    return 0;
}