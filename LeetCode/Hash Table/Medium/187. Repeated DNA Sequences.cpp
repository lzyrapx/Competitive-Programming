class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        if(s.size() == 0) return ans;
        if(s.size() <= 10) {
            return ans;
        }
        unordered_map<string,int>mp;
        for(int i = 0; i + 10 <= (int)s.size(); i++) {
            string tmp =  s.substr(i,10);
            if(mp[tmp]== 1) ans.push_back(tmp);
            mp[tmp]++;
        }
        return ans;
    }
};