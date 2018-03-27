#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int gcd ( int a , int b )
{
    return b == 0 ? a:gcd ( b , a%b ); 
}
int l,sx,sy,px,py;
int main()
{
    while (~scanf ("%d" ,&l ),l)
    {
        scanf ( "%d%d%d%d" , &sx , &sy , &px , &py );
        int dx = abs ( sx - px );
        int dy = abs ( sy - py );
        int d = gcd ( dx , dy );
        if ( abs ( px )> l || abs( py ) > l )
        {
            puts ("Out Of Range");
            continue;
        }
        if (d ==1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}