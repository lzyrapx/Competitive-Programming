#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1010] ;
    int n , m , i , j ;
    while(cin >> n >> m)
    {
        for(i = 0 ; i < n ; i ++)
            a[i] = i + 1 ;
        for(i = 1 ; i < m ; i ++)
        {
            next_permutation(a , a + n) ;
            if(i == m - 1)
            {
                for(j = 0 ; j < n -1 ; j ++)
                    cout << a[j] << " ";
                cout << a[n - 1] << endl ;
            }
        }
    }
    return 0;
}