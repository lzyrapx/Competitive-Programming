class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s.size() <= 1) return 0;
        
        stack<int>sta;
        int skip_idx = 0;
        int ans = 0;
        //用栈维护左括号，即在读取字符串的时候，遇到左括号就入栈。遇到右括号就出栈。
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                sta.push(i);
            }
            else if(s[i] == ')')
            {
                if(sta.empty()) //当前栈为空，说明当前的右括号并不构成括号匹配的子串,移到下一个位置
                {
                    skip_idx = i + 1;
                }
                else
                {
                    sta.pop(); //如果当前栈不为空，弹出栈顶元素,弹出一个左括号
                    if(sta.empty())
                    { //如果栈为空，说明栈正好剩下一个左括号和当前右括号配对，其子串长度 = 当前位置 - skip_idx位置 + 1
                        ans = max(ans, i - skip_idx + 1);
                    }
                    else
                    { //如果栈不为空，则栈剩下不止一个左括号，所以子串长度 = 当前位置 - 栈顶元素位置。
                        ans = max(ans, i - sta.top());
                    }
                }
            }
        }
        return ans;
    }
};