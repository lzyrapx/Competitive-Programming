/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-22 15:37:41
 */ 
class Solution {
public:
    // 保证有唯一答案
    // 就是简单地模拟栈
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) {
            return 0;
        }
        stack<int>stk;
        for(string s: tokens) {
            if(s.size() == 1 && !isdigit(s[0])) {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(s[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
            else {
                stk.push(atoi(s.c_str()));
            }
        }
        return stk.top();
    }
};