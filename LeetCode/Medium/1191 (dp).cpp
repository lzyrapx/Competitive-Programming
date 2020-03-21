/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 23:01:10
 */
class Solution {
public:
    int mod = 1e9 + 7;
    // 1 <= arr.length <= 10^5
    // -10^4 <= arr[i] <= 10^4
    // 1 <= k <= 10^5
    // 规约为连续子数组问题
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size() == 0) {
            return 0;
        }
        int sum = accumulate(arr.begin(), arr.end(), 0);
        // cout << sum << endl;
        int dp = arr[0];
        int ans = arr[0];
        int n = arr.size();
        for(int i = 1; i < min(k, 2) * n; i++) {
            dp = max(arr[i % n], dp + arr[i % n]);
            ans = max(dp, ans);
        }
        return max(0LL, max(1LL * ans, 1LL * max(0, k - 2) * sum + ans)) % mod;
    }
};