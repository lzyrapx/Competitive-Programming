class Solution {
public:
    // 找最长无重复字母的子串长度
    // 双指针
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int j = 0;
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while(mp[s[i]] > 1) {
                mp[s[j]]--;
                j++;
            }
            maxlen = max(maxlen,i - j + 1);
        }
        return maxlen;
    }
};