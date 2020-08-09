class Solution {
public:
    // 找到最长的子串，使得子串里每个字母的数量都 >= k, 求子串的长度
    int longestSubstring(string s, int k) {
        int len = s.size();
        if(len < k) {
            return 0;
        }
        if(len == 0) {
            return 0;
        }
        if(k < 2) {
            return len;
        }
        return dfs(s, k, 0, len);
    }
    int dfs(string s, int k, int start, int end) {
        if(end - start < k){ // 如果剩下的字符串长度少于 k，那肯定这里面没有答案
            return 0;
        }
        // map<int,int>mp; // TLE
        vector<int>mp(26, 0); // Accepted
        // mp.clear();
        for(int i = start; i < end; i++){
            mp[s[i] - 'a']++;
        }
        for(int i = start; i < end; i++) {
            if(mp[s[i] - 'a'] < k) {
                // dfs(start, end) = max(dfs(start, mid - 1), dfs(mid + 1, end))
                // s[i] 不存在
                return max(dfs(s, k, start, i), dfs(s, k, i + 1, end));
            }
        }
        return end - start;
    }
};