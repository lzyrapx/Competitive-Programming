/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-07 19:41:42
 */
class Solution {
public:
    // 1 <= A.length <= 50000
    // O(n^2)
    int subarrayBitwiseORs(vector<int>& A) {
        int sz = A.size();
        if(sz <= 1) {
            return sz;
        }
        vector<int>SumMask(sz, A[sz - 1]);
        for(int i = sz - 2; i >= 0; --i) {
            SumMask[i] = SumMask[i + 1] | A[i];
        }
        unordered_set<int>se;
        for(int i = 0; i < sz; i++) {
            int mask = A[i];
            se.insert(mask);
            for(int j = i + 1; j < sz; j++) {
                if((mask | SumMask[j]) == mask) {
                    break;
                }
                if((mask | A[j]) != mask) {
                    mask |= A[j];
                    se.insert(mask);
                }
            }
        }
        return se.size();
    }
};