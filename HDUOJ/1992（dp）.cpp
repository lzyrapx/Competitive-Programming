# include <stdio.h>
int dp[25] = {1,1,5,11} ;
int main ()
{
    int T, i, cas = 1, n;
    for(i = 4 ; i <= 22 ; i++)
        dp[i] = dp[i-1]+dp[i-2]*5+dp[i-3]-dp[i-4] ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n) ;
        printf ("%d %d\n", cas++, dp[n]) ;
    }
    return 0 ;
}