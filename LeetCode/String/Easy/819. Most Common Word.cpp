class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        map<string,int>mp;
        string tmp = "";
        for(auto c:paragraph) {
            if(c <= 'z' && c >= 'a') {
                tmp = tmp + c;
            }
            else if(c <= 'Z' && c >= 'A') {
                c= tolower(c);
                tmp = tmp + c;
            }
            else if(tmp.size() != 0) {
                mp[tmp]++;
                tmp.clear();
            }
        }
        if(tmp.size() != 0) {
            mp[tmp]++;
            tmp.clear();
        }
        for(auto c: banned) {
            mp[c] = 0;
        }
        int cnt = 0;
        string ans = "";
        for(auto x : mp){
            if(x.second > cnt) {
                cnt = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};