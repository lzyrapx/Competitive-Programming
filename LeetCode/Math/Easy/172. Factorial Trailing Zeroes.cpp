class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 4) return 0;
        int ans = 0;
        // 计算因子5有多少个
        while(n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};