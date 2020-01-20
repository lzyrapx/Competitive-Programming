/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-19 12:29:14
 */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>>ans;
        if(A.size() == 0) return ans;
        for(int i = 0; i < A.size(); i++) {
            vector<int>tmp;
            for(int j = A[0].size() - 1; j >= 0; --j) {
                tmp.push_back(A[i][j] ^ 1);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
