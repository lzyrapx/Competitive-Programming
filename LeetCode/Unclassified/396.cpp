/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 14:16:42
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 14:16:42
 */
class Solution {
public:
    // 0 <= A.size() <= 1e5
    int maxRotateFunction(vector<int>& A) {
        if(A.size() <= 1) return 0;
        long long tot = 0;
        long long sum = 0;
        for(int i = 0; i < A.size(); i++) {
            tot += A[i];
            sum += i * A[i];
        }
        long long ans = sum;
        reverse(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++) {
            sum = sum + (tot - A[i] * A.size());
            // cout << "sum = " << sum << endl;
            ans = max(ans, sum);
        }
        return ans;
    }
};