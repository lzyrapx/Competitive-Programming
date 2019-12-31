/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 14:40:03
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>ans;
        for(int i = 0 ; i < A.size(); i++) {
            ans.push_back(A[i] * A[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};