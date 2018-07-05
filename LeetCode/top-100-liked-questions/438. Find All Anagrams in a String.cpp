class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>mps(256,0);
        vector<int>mpp(256,0);
        vector<int>ans;
        if(p.size() > s.size()) return ans;
        for(int i = 0; i < p.size(); i++) {
            mps[s[i]]++;
            mpp[p[i]]++;
        }
        if(mps == mpp) ans.push_back(0);
        for(int i = p.size(); i < s.size(); i++) 
        {
            mps[s[i]]++;
            mps[s[i - p.size()]]--;
            if(mps == mpp) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};