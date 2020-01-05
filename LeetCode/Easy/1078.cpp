/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 23:31:38
 */
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>ans, s;
        stringstream ss(text);
        string word;
        while(ss >> word) {
            s.push_back(word);
        }
        for(int i = 0; i < s.size() - 2; i++) {
            if(s[i] == first && s[i + 1] == second) {
                ans.push_back(s[i + 2]);
            }
        }
        return ans;
    }
};