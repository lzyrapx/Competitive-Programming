/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 16:17:41
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0, j = 1; i < A.size() && j < A.size();) {
            if(A[i] % 2 == 0) {
                i += 2;
            }
            else if(A[j] % 2 == 1) {
                j += 2;
            }
            else {
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};