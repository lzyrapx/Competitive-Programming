class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mp;
        for(char ch: magazine) {
            mp[ch] += 1;
        }
        for(char ch : ransomNote) {
            mp[ch] -= 1;
            if(mp[ch] <= -1) return false;
        }
        return true;
    }
};