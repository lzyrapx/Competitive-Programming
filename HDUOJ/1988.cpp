#include<bits/stdc++.h>
using namespace std;
int n, a[35] ;
int ans[110];
int num;
int find(int x)
{
    
    for (int i = 1 ; i <= n ; i++)
        if (abs(a[i]) == x) return i ;
    return 0 ;
}
void change(int pos)
{

    for(int i = 1, j = pos ; i < j ; i++, j--)
    {
       swap(a[i],a[j]);
    }
    for(int i = 1 ; i <= pos ; i++) a[i] = -a[i] ;
}
void solve()
{
    int pos ;
    num = 0 ;
    for (int i = n ; i >= 1 ; i--)
    {
        if (a[i] == i) continue ;
        pos = find(i) ;
        if (pos != 1)
        {
            change(pos);
            ans[num++] = pos;
        }
        if (a[1] > 0)
		{
            ans[num++] = 1;
            a[1] = -a[1];
        }
        if (i != 1)
        {
            ans[num++] = i;
            change(i);
        }
        else
		{
        	
            ans[num++] = 1;
            a[i] = -a[i];
        }
    }
}
int main()
{
    int t,cas = 1;
    scanf ("%d", &t) ;
    while (t--)
    {
        scanf ("%d", &n) ;
        for (int i = 1 ; i <= n ; i++)scanf("%d", &a[i]);
        
        solve();
        
        printf ("%d %d", cas++, num) ;
        for (int i = 0 ; i < num ; i++)
        {
            printf (" %d", ans[i]) ;
        }
        puts ("") ;
    }
    return 0 ;
}