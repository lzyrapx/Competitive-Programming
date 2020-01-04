/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 18:26:34
 */
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(auto c : chars) {
            mp[c]++;
        }
        int ans = 0;
        for(auto s: words) {
            map<char, int>mp2(mp);
            int cnt = 0;
            for(auto c: s){
                if(mp2[c] > 0) {
                    cnt ++;
                    mp2[c]--;
                    if(cnt == s.size()) {
                        ans += s.size();
                    }
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};