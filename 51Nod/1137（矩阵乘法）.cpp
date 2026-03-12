#include <bits/stdc++.h>
using namespace std;
const int N=100;  
struct Mat  
{  
    int a[N][N];  
};  
int n;  
Mat mitriplus(Mat A,Mat B)  
{  
    Mat ans;  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<n;j++)  
        {  
            ans.a[i][j]=0;  
            for(int k=0;k<n;k++)  
            ans.a[i][j]+=A.a[i][k]*B.a[k][j];  
        }  
    }  
    return ans;  
}  
int main()  
{  
   	cin>>n;
    Mat A,B;  
    for(int i=0;i<n;i++)  
        for(int j=0;j<n;j++)  
        	scanf("%d",&A.a[i][j]);  
    for(int i=0;i<n;i++)  
        for(int j=0;j<n;j++)  
        	scanf("%d",&B.a[i][j]);  
    Mat ans=mitriplus(A,B);  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<n-1;j++)  
            printf("%d ",ans.a[i][j]);  
               
        printf("%d\n",ans.a[i][n-1]);  
    }  
    return 0;  
}  

