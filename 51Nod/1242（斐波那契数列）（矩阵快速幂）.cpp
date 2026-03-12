#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+9;
struct Mat
{
	ll matrix[2][2];
};
Mat mul(Mat a, Mat b)
{
	Mat c;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c.matrix[i][j]=0;
			for(int k=0;k<2;k++)
			{
				c.matrix[i][j]+=(a.matrix[i][k]*b.matrix[k][j]);
			}
			c.matrix[i][j]%=mod;
		}
	}
	return c;
}
Mat mat;
Mat solve(ll m)
{
	Mat res=mat;
	while(m)
	{
		if(m&1)res=mul(mat,res);
		mat=mul(mat,mat);
		m>>=1;
	}
	return res;
}
int main()
{
	ll n;
	cin>>n;
	if(n==0)
	{
		return 0*printf("0");
	}
	if(n==1)
	{
		return 0*printf("1");
	}
	if(n==2)
	{
		return 0*printf("1");
	}
	else
	{
		n--;
		mat.matrix[0][0]=1;
		mat.matrix[0][1]=1;
		mat.matrix[1][0]=1;
		mat.matrix[1][1]=0;
		Mat ans=solve(n-1);
		cout<<ans.matrix[0][0]<<endl;
	}
	
	return 0;
}