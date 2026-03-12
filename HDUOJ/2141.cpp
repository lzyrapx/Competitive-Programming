#include<stdio.h>
#include<iostream>
#include<string.h>
#include<set>
using namespace std;
const int MAX_N=505;
int A[MAX_N];
int B[MAX_N];
int C[MAX_N];
set<int> D;
int L, M, N, S;
bool Find(int key)
{
    for(int i=0; i<M; i++)
    {
        if(D.find(key-C[i])!=D.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T=0;
    while(scanf("%d %d %d",&L, &N, &M)!=EOF)
    {
 		D.clear();   	
        for(int i=0; i<L; i++)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0; i<N; i++)
        {
            scanf("%d",&B[i]);
        }
        for(int i=0; i<M; i++)
        {
            scanf("%d", &C[i]);
        }
        
        for(int i=0; i<L; i++)
        {
            for(int j=0; j<N; j++)
            {
                D.insert(A[i]+B[j]);
            }
        }
        scanf("%d",&S);
        printf("Case %d:\n",++T);
        while(S--)
        {
            int x;
            scanf("%d",&x);
            if(Find(x))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}

---------------二分

#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[505],b[505],c[505];
int ab[250005];
bool Binary_Search( int a, int l , int R )
{
	//二分
   if( l > R )
     return false;
   int mid = ( l + R ) / 2;
    if (ab[mid] == a )
    return true;
   else if( ab[mid] > a)
    Binary_Search( a, l, mid-1);
   else
    Binary_Search( a, mid+1, R);
}
int main()
{
 	int l,n,m;
 	int i,j,k;
 	int s,sum,cnt = 1;
 	while( cin >> l >> n >> m )
 	{
 	 	
		for( i = 0; i < l; i++)
  		 cin >> a[i];
  		 
 		 for( i = 0; i < n; i++)
  		 cin >> b[i];
  		 
 		 for( i = 0; i < m; i++)
   		 cin >> c[i];
   		
 		 for(k=0, i=0;i<l; i++)
  		 {
  		 	for( j=0; j<n; j++)
            {
            	ab[k++] = a[i] + b[j];
			}
		   }
      	sort( ab, ab + k );
 		 cin >> s;
  		cout << "Case " << cnt++ << ":"<<"\n";
 		 for( i = 0; i < s; i++ )
 		 {
  			 cin >> sum;
   			for( j = 0; j < m; j++)
    		if ( Binary_Search(sum-c[j] , 0 , k-1) ) //查找是否有满足的和
    		 break;
  			 if( j == m)
   			 puts("NO"); 
  			 else
    			puts("YES");
  		}
	}
 		return 0;
}

