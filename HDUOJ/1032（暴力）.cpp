#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	long long ans=0;
	while(~scanf("%d%d",&n,&m)){
		printf("%d %d ",n,m);
        if(n>m)
            swap(n,m);
         long long max=0;
        for(int i=n;i<=m;i++)
        {
            long long t=i;
            long long cnt=1;
            while(t!=1)
            {
                if(t%2==0)
                    t/=2;
                else
                    t=(t*3+1);
                cnt++;
            }
            if(cnt>max)
                max=cnt;
        }
        printf("%lld\n",max);
	}
	
	return 0;
}