class Solution {
public:
    long long numTrees(int n) {
        if(n==0)return 0;
        if(n==1) return 1;
        vector<long long>dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++) { //依次计算dp(2),dp(3)...dp(n)
            dp[i] = 0;
            for(int j=0;j<i;j++) { //根据递归式计算 dp(i)= dp(0)*dp(i-1)+dp(1)*dp(i-2) + ... + dp(i-1)dp(0) 
                dp[i] += (dp[j] * dp[i-1-j]); 
            }
        }
        return dp[n];
    }
};
/*
https://blog.csdn.net/doc_sgl/article/details/8880468

另类递推式：h(n)=h(n-1)*(4*n-2)/(n+1);
递推关系的解为：h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
递推关系的另类解为：h(n)=C(2n,n)-C(2n,n+1)(n=0,1,2,...)
*/