class Solution {
public:
    map<string,vector<string> > mp;
    
    vector<string>combine(string word, vector<string>pre)
    {
        for(int i = 0; i < pre.size(); i++)
        {
            pre[i] += " " + word;
        }
        return pre;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0 || wordDict.size() == 0) return vector<string>();
        vector<string> ans;
        for(auto ss :wordDict) //整个字符串都是
        {
            if(ss == s)
                ans.push_back(ss);
        }
        for(int i = 1; i < s.size(); i ++)
        {
            string word = s.substr(i);
            for(auto ss : wordDict)
            {
                if(ss == word)
                {
                    string remain = s.substr(0,i);
                    vector<string> pre = combine(word,wordBreak(remain,wordDict));
                    ans.insert(ans.end(),pre.begin(), pre.end());
                } 
            }
        }
        return ans;
    }
};