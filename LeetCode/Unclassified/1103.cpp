/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-11 01:47:46
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-11 01:47:46
 */
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people, 0);
        int i = 0;
        int idx = 0;
        while(candies) {
            i += 1;
            if(i > candies) {
                ans[idx % num_people] += candies;
                break;
            } else {
                ans[idx % num_people] += i;
            }
            idx += 1;
            candies -= i;
        }
        return ans;
        
    }
};