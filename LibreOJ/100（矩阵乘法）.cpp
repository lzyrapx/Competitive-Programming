#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[maxn][maxn],B[maxn][maxn],C[maxn][maxn];
int n,m,p;
void matrix_mul()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            C[i][j] = 0;
            for(int k = 0; k < p; k++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j] )%mod;
            }
            if(C[i][j] < 0) C[i][j] = (C[i][j] + mod)%mod;
        }
    }
}
int main()
{
    cin>>n>>p>>m;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
        {
        	cin>>A[i][j];
		}
            
    for(int i = 0; i < p; i++)
        for(int j = 0; j < m; j++)
        {
        	cin>>B[i][j];
		}
            
    matrix_mul();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<C[i][j];
            if(j == m-1) cout<<endl;
            else cout<<" ";
        }
    }
    
	return 0;
}