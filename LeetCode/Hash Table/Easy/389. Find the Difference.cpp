class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int>mp;
        
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        char ans;
        for(int i = 0; i < m; i++) {
            if(mp[t[i]]) mp[t[i]]--;
            else if(mp[t[i]] == 0){
                ans = t[i];
            }
        }
        return  ans;
    }
};