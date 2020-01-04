/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 20:45:32
 */
class Solution {
public:
    // 1 <= queries.length <= 2000
    // 1 <= words.length <= 2000
    // 1 <= queries[i].length, words[i].length <= 10
    int f(string s) {
        map<char,int>mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] += 1;
        }
        for(int i = 0; i < 26; i++) {
            if(mp[char(i + 'a')] > 0) {
                return mp[char(i + 'a')];
            }
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        vector<int>q;
        vector<int>w;
        for(auto s: queries) {
            q.push_back(f(s));
        }
        for(auto s: words) {
            w.push_back(f(s));
        }
        for(int i = 0; i < queries.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < words.size(); j++) {
                if(q[i] < w[j]) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};