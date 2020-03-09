/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-09 00:26:16
 */
class Solution {
public:
    // 1 <= A.length <= 40000
    // close to LIS
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() == 1) {
            return 1;
        }
        int ans = 1;
        int len = 1;
        int last = 0; // < : last < 0; > last > 0
        for(int i = 1; i < A.size(); i++) {
            if(((i == 1) && A[i - 1] != A[i]) ||
              (last < 0 && A[i - 1] > A[i]) ||
              (last > 0 && A[i - 1] < A[i])) {
                len++;
                last = A[i - 1] - A[i];
            }
            else {
                ans = max(ans, len);
                last = A[i - 1] - A[i];
                if(last == 0) { // A[i - 1] == A[i]
                    len = 1;
                }
                else{
                    len = 2;
                }
            }
        }
        return max(ans, len);
    }
};