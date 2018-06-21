class Solution {
public:
    //  words : that are all of the same length
    // 先用map把word里的单词保存下来
    // 再暴力截取s中与word相等长度的子串
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(s.size() == 0 || words.size() == 0) return ans;
        int sz = words[0].size();
        // cout << "sz = " << sz << endl;
        int len = words.size() * sz;
        if(len > s.size()) return ans;
        map<string,int>mp;
        for(int i = 0; i < words.size(); i++) 
        {
            if(mp.find(words[i]) == mp.end()) 
            {
                mp[words[i]] = 1;
            }
            else mp[words[i]] ++;
        }
        
        for(int i = 0; i < s.size(); i++) 
        {
            map<string,int>mmp;
            int j = 0;
            for(j = i; j < i + len; j = j + sz) 
            {
                string ss = s.substr(j,sz);
                // cout << ss << endl;
                if(mmp.find(ss) == mmp.end())  {
                    mmp[ss] = 1;
                }
                else mmp[ss] ++;
                
                if(mp.find(ss) == mp.end()) break;
                if(mmp[ss] > mp[ss]) break;
            }
            if(j >= i + len) ans.push_back(i);
        }
        return ans;
    }
};