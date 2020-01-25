/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-25 16:04:25
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) {
            return 0;
        }
        vector<int>res(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) {
                res[i] = res[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                res[i] = max(res[i], res[i + 1] + 1);
            }
        }
        int sum = 0;
        for(auto x: res) {
            sum += x;
        }
        return sum;
    }
};