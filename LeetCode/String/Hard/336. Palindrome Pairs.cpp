class Solution {
public:
    bool isPalindrome(string s)
    {
        if(s.size() == 0) return true;
        if(s.size() == 1) return true;
        string ss(s.rbegin(),s.rend());
        if(s == ss) return true;
        else return false;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector< vector<int> >ans;
        
        if(words.size() <= 1) return ans;
        
        map<string,int>mp;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(),s.end());  
            mp[s]=i;
        }
        for(int i = 0; i < words.size(); i++) 
        {
            for(int j = 0; j <= words[i].size(); j++) 
            {
                string str1 = words[i].substr(0,j);
                string str2 = words[i].substr(j);
                if(mp.count(str1) != 0 && isPalindrome(str2) && mp[str1] != i) {
                    ans.push_back( {i,mp[str1]});
                }
                if(str1.size() != 0 && mp.count(str2) && isPalindrome(str1) && mp[str2] != i) {
                    ans.push_back( {mp[str2], i} );
                }
            }
        }
        return ans;
    }
};