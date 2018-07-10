class Solution {
public:
    // words的一个字符串必须要有licensePlate里的全部非数字，只能多不能少
    int check(string s, map<char,int>&mp) {
        map<char,int>cur;
        for(auto ch : s) {
            cur[tolower(ch) - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cur[i] < mp[i]) return false;
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int>mp;
        for(auto ch : licensePlate) {
            if(isalpha(ch)) {
                mp[tolower(ch) -'a']++;
            }
        }
        int idx = 0;
        int minn = INT_MAX;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string s = words[i];
            if(check(s,mp) && s.size() < minn) {
                minn = s.size();
                idx = i;
            }
        }
        return words[idx];
    }
};