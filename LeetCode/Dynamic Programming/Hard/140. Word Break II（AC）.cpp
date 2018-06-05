class Solution {
public:
    bool dfs(string&s, set<string>& dict, int idx ,vector<bool>&possible, vector<string>& ans,string& item )
    {
         bool res = false;
        if(idx==s.size()){   
            ans.push_back(item.substr(0, item.size()-1));
            return true;
        }
        for (int i = idx; i<s.size(); ++i)
        {
		    string word = s.substr(idx, i - idx + 1);

		    if (dict.find(word) != dict.end() && possible[i + 1] == true) 
            {
			    item += (word + " ");
			    if (dfs(s, dict, i + 1, possible, ans, item)) res = true;
			    else possible[i + 1] = false;	
			    item.resize(item.size() - word.size() - 1); 
		    }
	    }  
	    return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        set<string> dict(wordDict.begin(),wordDict.end());        
        vector<bool> possible(s.size() + 1, true);
        vector<string> ans;
        string item;
        dfs(s,dict,0,possible, ans, item);
        return ans;     
    }   
};