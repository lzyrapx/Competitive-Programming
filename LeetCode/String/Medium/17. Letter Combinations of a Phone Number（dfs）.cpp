class Solution {
public:
    void dfs(string digit, int pos, string &tmp,vector<string>&ans, vector<string>&letter)
    {
        if(pos == digit.size()) {
            ans.push_back(tmp);
            return;
        }
        for(auto c: letter[digit[pos] - '0']) {
            tmp.push_back(c);
            dfs(digit, pos + 1, tmp, ans, letter);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size() == 0) return ans;
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string tmp = "";
        dfs(digits,0,tmp,ans,letter);
        return ans;
    }
    
};