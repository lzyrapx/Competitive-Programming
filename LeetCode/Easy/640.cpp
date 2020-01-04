/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 17:39:04
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 17:39:04
 */
class Solution {
public:
    void solve(string s, int& a, int& b) {
        if(s.empty()) return ;
        if(s[0] != '-' && s[0] != '+') {
            return solve('+' + s, a, b);
        }
        int i = 1;
        // find the position of "x"
        while(i < s.size() && s[i] != '-' && s[i] != '+') {
            i++;
        }
        string tmp = s.substr(1, i - 1);
        if(tmp.back() == 'x') {
            tmp.pop_back();
            int coeff = tmp.empty()? 1 : stoi(tmp); // coefficient of "x"
            a = (s[0] == '-')? a - coeff: a + coeff;
        }
        else {
            int val = stoi(tmp);
            b = (s[0] == '-') ? b - val : b + val;
        }
        // solve the expression after the "x"
        solve(s.substr(i), a, b);
    }
    // first: move all "x" to the left side
    // second: move all numbers to the right side
    string solveEquation(string equation) {
        int pos = equation.find('=');
        string left = equation.substr(0, pos);
        string right = equation.substr(pos + 1, equation.size() - pos - 1);
        int a = 0, b = 0;
        int c = 0, d = 0;
        // ax + b = cx + d
        solve(left, a, b);
        solve(right, c, d);
        if(a == c) {
            // x = x
            if(b == d) {
                return "Infinite solutions";
            }
            // 0 = 2
            else {
                return "No solution";
            }
        }
        else { 
            return "x=" + to_string((d - b)/ (a - c));
        }
    }
};