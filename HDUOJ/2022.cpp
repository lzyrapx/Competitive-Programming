#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,m,i,j,x,y,a[100][100],max;
    while(cin>>n>>m)
    {
    	max=0;
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=m;j++)
    		{
    			cin>>a[i][j];
				if(abs(a[i][j])>max)
				{
					max=abs(a[i][j]);
					x=i,y=j;
				}
			}
    	}
    	cout<<x<<" "<<y<<" "<<a[x][y]<<endl;
    }
	return 0;
}