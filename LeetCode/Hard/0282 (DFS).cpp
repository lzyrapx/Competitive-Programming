/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-26 21:37:57
 */
class Solution {
public:
    void dfs(string num, long long target, string cur, long long sum, long long prev, vector<string>&ans) {
        if(num.size() == 0) {
            if(sum == target) {
                ans.push_back(cur);
            }
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            string s = num.substr(0, i + 1);
            if(s.size() > 1 && s[0] == '0') {
                continue;
            }
            stringstream ss(s);
            long long v = 0;
            ss >> v;
            if(cur.size() == 0) {
                dfs(num.substr(i + 1), target, s, v, v, ans);
            }
            else{
                dfs(num.substr(i + 1), target, cur + "+" + s, sum + v, v, ans);
                dfs(num.substr(i + 1), target, cur + "-" + s, sum - v, -v, ans);
                dfs(num.substr(i + 1), target, cur + "*" + s, (sum - prev) + prev * v, prev * v, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        dfs(num, target, "", 0, 0, ans);
        return ans;
    }
};