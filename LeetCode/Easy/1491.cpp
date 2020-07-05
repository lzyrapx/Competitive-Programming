/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-06 00:54:37
 */ 
class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int sum = 0;
        for(int i = 0; i < salary.size(); i++) {
            if(mx <= salary[i]) {
                mx = salary[i];
            }
            if(mn >= salary[i]) {
                mn = salary[i];
            }
            sum += salary[i];
        }
        return 1.0 * (sum - mx - mn) / (salary.size() - 2);
    }
};