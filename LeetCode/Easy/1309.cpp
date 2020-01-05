/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 13:56:30
 */
class Solution {
public:
    string freqAlphabets(string s) {
        if(s.size() == 0) return "";
        string ans = "";
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] != '#') {
                ans += (s[i] - '1' + 'a');
            }
            else {
                int num = (s[i - 1] - '1' + 1) + 10 * (s[i - 2] - '1' + 1);
                // cout << num << endl;
                ans += (num - 1 + 'a');
                i -= 2;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};