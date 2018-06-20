class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        map<int,int>mp;
        int cnt = 0;
        for(auto x : indexes) {
            mp[x] = cnt++;
        }
        for(int i = 0; i < S.size();) {
            if(mp.count(i) && (S.substr(i, sources[mp[i]].size()) == sources[mp[i]])) {
                ans = ans + targets[mp[i]];
                i += sources[mp[i]].size();
            }
            else {
                ans = ans + S[i];
                i++;
            }
        }
        return ans;
    }
};