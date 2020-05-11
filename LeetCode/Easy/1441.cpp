/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-10 23:34:22
 */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        for(int i = 1; i <= n; i++) {
            for(auto x: target) {
                if(x == i) {
                    ans.push_back("Push");
                    break;
                }
                if(x > i) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    break;
                }
            }
        }
        return ans;
    }
};