class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        int len = s.size();
        for(int i = 0; i < len; i++) 
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') //栈维护左括号
            {
                sta.push((char)s[i]);
            }
            else //遇到右括号的pop
            {
                if(sta.empty())
                {
                    return false;
                }
                if(s[i] == ')')
                {
                    char c = sta.top();sta.pop();
                   
                    if(c != '(')
                    {
                        return false;
                    }
                }
                if(s[i] == '}')
                {
                    char c = sta.top();sta.pop();
                    if(c != '{')
                    {
                        return false;
                    }
                }
                if(s[i] == ']')
                {
                    char c = sta.top();sta.pop();
                    if(c != '[')
                    {
                        return false;
                    }
                }
            }
        }
        if(!sta.empty())return false;
        return true;
    }
};