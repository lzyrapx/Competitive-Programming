class Solution {
public:
    // 给一个字符串s，计算具有相同数字0和1的非空（连续）子字符串的数量
    int countBinarySubstrings(string s) {
        if(s.size() <= 1) return 0;
        vector<int> dp(s.size() + 1, 0);
        int ans = 0;
        int pre = 0;
        int now = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i-1] == s[i]) {
                now++;
            }
            else {
                pre = now;
                now = 1;
            }
            if(pre >= now) ans++;
        }
        return ans;
    }
};