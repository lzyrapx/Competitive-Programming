/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-18 22:31:00
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-18 22:31:00
 */
class Solution {
public:
    // 1 <= A.size() <= 5000
    bool isIdealPermutation(vector<int>& A) {
        int res = 0; 
        for(int i = 0 ; i < A.size() - 1; i++) {
            if(res > A[i + 1]) { 
                return false;
            }
            res = max(res, A[i]);
        }
        return true;
    }
};