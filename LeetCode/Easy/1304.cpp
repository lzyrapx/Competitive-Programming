/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 19:22:40
 */
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n == 0) {
            return ans;
        }
        if(n % 2 == 0) {
            for(int i = 1; i <= n / 2; i++) {
                ans.push_back(-1 * i);
            }
            for(int i = 1; i <= n / 2; i++) {
                ans.push_back(i);
            }
        }
        else {
            for(int i = 1; i <= n / 2; i++) {
                ans.push_back(-1 * i);
            }
            ans.push_back(0);
            for(int i = 1; i <= n / 2; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};