class Solution {
public:
    const int mod = 1e9 + 7;
    int checkRecord(int n) {
        if(n == 0) return 0;
        if(n == 1) return 3;
        if(n == 2) return 8;
        // P[i] 表示前 i 个 字母中以 P 结尾的排列方案数，不存在 A
        vector<long long>P(n + 1, 0);
        // PL 表示前 i 个 字母中以 P 或者 L 结尾的排列方案数 ，不存在 A
        vector<long long>PL(n + 1,0);
        P[0] = 1; 
        PL[0] =  1;
        PL[1] = 2;
        for(int i = 1; i <= n; i++) //计算不含有 A 的排列数
        {
            P[i] = PL[i-1] % mod;
            if(i > 1)
            {//P[i]已经更新了，L[i]只能当前一个字符是P，或者前一个字符是P且再前一个字符是P
                PL[i] = (P[i] + P[i-1] + P[i-2]) % mod;
            }
        }
        long long ans = PL[n];
        for(int i = 0;i < n; i++) //将一个A插入
        {
            long long tmp = (PL[i] * PL[n - i - 1]) % mod;
            ans = (ans + tmp) % mod;
        }
        return ans % mod;
    }
};