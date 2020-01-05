/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 00:43:10
 */
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char>st;
        string ans;
        for(int i = 0 ;i < S.size(); i++) {
            if(S[i] == '(') {
                 st.push(S[i]);
                if(st.size() != 1) {
                   ans = ans + S[i];
                }
            }
            else {
                if(st.size() != 1) {
                    ans = ans + S[i];
                }
                st.pop();
            }
        }
        return ans;
    }
};