#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55][55];
char str1[55],str2[55];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int ans = 0;
		memset(dp,0,sizeof(dp));
		scanf("%s%s",str1+1,str2+1);
		int length1 = strlen(str1+1);
		int length2 = strlen(str2+1);
		for(int len1 = 0; len1 <= length1; len1++)
		{
			for(int len2 = 0; len2 <= length2; len2++)
			{
				for(int l1 = 1, r1 = l1 + len1 - 1; r1 <= length1; l1++, r1++)
				{
					for(int l2 = 1, r2 = l2 + len2 - 1; r2 <= length2; l2++, r2++)
					{
						if(len1==0&&len2==0)
						{
							dp[l1][r1][l2][r2] = 1;	
						}
						if(len1==0&&len2==1||len1==1&&len2==0)
						{
							dp[l1][r1][l2][r2] = 1;
						}
						if(str1[l1]==str1[r1] && r1 > l1)
						{
							dp[l1][r1][l2][r2] |= dp[l1+1][r1-1][l2][r2];
						}
						if(str1[l1]==str2[r2] && r1 >= l1 && r2 >= l2)
						{
							dp[l1][r1][l2][r2] |= dp[l1+1][r1][l2][r2-1];
						}
						if(str2[l2]==str1[r1] && r1 >= l1 && r2 >= l2)
						{
							dp[l1][r1][l2][r2] |= dp[l1][r1-1][l2+1][r2];
						}
						if(str2[l2]==str2[r2] && r2 > l2)
						{
							dp[l1][r1][l2][r2] |= dp[l1][r1][l2+1][r2-1];
						}
						if(dp[l1][r1][l2][r2])
						{
							ans = max(ans,r1-l1+1+r2-l2+1);
						}
					}	
				}	
			}	
		} 
		cout<<ans<<endl;
	}
	return 0;
}