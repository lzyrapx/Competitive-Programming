class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >ans;
        if(strs.size() <= 1) {
            cout << strs[0] << endl;
            ans.push_back(vector<string>{strs[0]});
            return ans;
        }
        map<string,int>mp;
        int pos = 0;
        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(mp.find(tmp) != mp.end()) {
                ans[mp[tmp]].push_back(strs[i]);
            }
            else {
                ans.push_back(vector<string>{strs[i]});
                mp[tmp] = pos;
                pos++;
            }
        }
        return ans;
        
    }
};