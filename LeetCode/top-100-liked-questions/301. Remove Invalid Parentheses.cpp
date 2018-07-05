class Solution {
public:
    bool isVail(string s)
    {
        int cnt = 0;
        for(char c : s)
        {
            if(c == '(') cnt++;
            else if(c == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    void dfs(string s, int begin, int num1, int num2, vector<string>&ans)
    {
        if(num1 == 0 && num2 == 0)
        {
            if(isVail(s)) ans.push_back(s);
        }
        else
        {
            for(int i = begin; i < s.size(); i++) {
                string tmp = s;
                if(num2 == 0 && num1 > 0 && tmp[i] == '(')
                {
                    if(i == begin || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1 - 1, num2, ans);
                    }
                }
                if(num2 > 0 && tmp[i] == ')')
                {
                    if(i == begin || tmp[i] != tmp[i - 1])
                    {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1, num2 - 1, ans);
                    }
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int num1 = 0; //记录左括号要remove的个数
        int num2 = 0; //记录右括号要remove的个数
        for(char c : s)
        {
            num1 += (c == '(');
            if(num1 == 0) {
                num2 += (c == ')');
            }
            else {
                num1 -= (c == ')');
            }
        }
        vector<string>ans;
        dfs(s, 0, num1, num2, ans);
        return ans;
    }
};