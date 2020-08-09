class Solution {
public:
    // 构造满足以下条件的 2 * n 的0-1矩阵,构造不了就输出空矩阵
    // 1. 第一行的和为 upper
    // 2. 第二行的和为 lower
    // 3. 第 i 列的和为 colsum[i]
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>>ans(2, vector<int>(colsum.size(), 0));
        int colSum = 0;
        for(int i = 0; i < colsum.size(); i++) {
            colSum += colsum[i];
        }
        if(colSum != upper + lower) {
            return {};
        }
        // 处理colsum[i]==2的情况
        int a = 0; // 第一行
        int b = 0; // 第二行
        for(int i = 0; i < colsum.size(); i++) {
            if(colsum[i] == 2) {
                ans[0][i] = 1;
                ans[1][i] = 1;
                a++;
                b++;
            }
        }
        if(a > upper || b > lower) {
            return {};
        }
        for(int i = 0 ; i < colsum.size(); i++) {
            if(colsum[i] == 1) {
                if(a < upper) {
                    ans[0][i] = 1;
                    a++;
                }
                else if(b < lower) {
                    ans[1][i] = 1;
                    b++;
                }
                else {
                    return {};
                }
            }
        }
        return ans;
    }
};