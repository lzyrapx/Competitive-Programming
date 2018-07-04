class Solution {
public:
    // Given a string S and a string T, 
    // find the minimum window in S which will contain all the characters in T in complexity O(n)
    // 滑动窗口
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        if(t.size() > s.size()) return "";
        map<char,int>mp;
        for(auto x : t) {
            mp[x]++; // map 只保存t中的字符串，在s中匹配到一个就(删)减一个
        }
        string ans;
        int left = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        for(int right = 0; right < s.size(); right++)
        {
            if(mp.find(s[right]) != mp.end()) // 滑动窗口右端点
            {
                mp[s[right]]--; // 移走了t中的字符串, 代表s中有字符串s[right]
                if(mp[s[right]] >= 0) cnt++;
                while(cnt == t.size()) // 当前窗口[left, right]中包括了t中所有的字符
                {
                    if(right - left + 1 < minlen) { //更新答案
                        minlen = right - left + 1;
                        ans = s.substr(left, minlen);
                    }
                    // 如果当前字符s[left]是t中的字符串
                    if(mp.find(s[left]) != mp.end()) {
                        mp[s[left]]++; // 补回来
                        if(mp[s[left]] > 0) cnt--;
                    }
                    left++; // 滑动窗口左端点, 移动left来去掉当前窗口中不属于t中的字符串
                }
            }  
        }
        return ans;
    }
};