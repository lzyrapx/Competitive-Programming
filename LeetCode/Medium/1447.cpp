class Solution {
public:
    // 返回 0-1 中间，分母少于等于 n 的所有分数
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        if(n <= 1) {
            return ans;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(__gcd(i, j) == 1) {
                    ans.push_back(to_string(j)+"/"+to_string(i));
                }
            }
        }
        return ans;
    }
};