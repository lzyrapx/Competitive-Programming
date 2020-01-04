/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 00:18:39
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 00:18:39
 */
class Solution {
public:
    int calc(vector<int>& arr1, vector<int>& arr2, int a, int b) {
        int ans = 0;
        int MinV = arr1[0] + a * arr2[0];
        int MaxV = arr1[0] + a * arr2[0];
        for(int i = 1; i < arr1.size(); i++) {
            int cur = arr1[i] + a * arr2[i] + b * i;
            ans = max(ans, max(abs(cur - MinV), abs(cur - MaxV)));
            MinV = min(cur, MinV);
            MaxV = max(cur, MaxV);
        }
        return ans;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        return max(max(calc(arr1, arr2, 1,1), calc(arr1, arr2, 1, -1)), 
                   max(calc(arr1, arr2, -1,1),calc(arr1, arr2, -1,-1)));
    }
};