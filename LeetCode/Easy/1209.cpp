/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 15:03:47
 */
class Solution {
public:
    // 1 <= s.length <= 1e5, 2 <= k <= 1e4
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>ve;
        string ans;
        for(auto ch: s) {
            if(ve.empty() || ve.back().first != ch) {
                ve.push_back({ch, 0});
            }
            ve.back().second += 1;
            if(ve.back().second == k) {
                ve.pop_back();
            }
        }
        for(auto& v : ve){
            ans += string(v.second, v.first);
        }
        return ans;
    }
};