/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 19:29:56
 */ 
class Solution {
public:
    // 斜对角是 1， 其实就是让每一行最后的0的个数需要大于等于n-1-行数.
    // 做法：贪心。
    // 转化成一维，每个数字表示这一行的从右边开始的连续 0 的个数，
    // 然后题目转化成了把这个一维数组调整成满足 arr[i]>=arr.size()-1-i 的最小步数,然后贪心即可。
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>row;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            for(int j = m - 1; j >= 0; --j){
                if(grid[i][j] != 0) {
                    break;
                }
                tmp++;
            }
            row.push_back(tmp);
        }
        int ans = 0;
        int i = 0;
        while(row.size() > 0) {
            int pos = n - 1 - i;
            int j = 0;
            while(j < row.size()) {
                if(row[j] >= pos) break;
                j++;
             }
            if(j == row.size()) return -1;
            ans += j; // 将那一行，整行换上来
            row.erase(row.begin() + j);
            i++;
        }
        return ans;
    }
};