/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 18:54:52
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 18:54:52
 */
class Solution {
public:
    // only "+" and "-" and "/"
    // return a fraction
    string fractionAddition(string expression) {
        stringstream ss(expression);
        char op;
        int a, b, c , d;
        ss >> a;
        ss >> op;
        ss >> b;
        while(ss >> c) {
            ss >> op;
            ss >> d;
            solve(a, b, c, d);
        }
        cout << a << " " << b << endl;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            return "-" + to_string(abs(a)) + "/" + to_string(abs(b));
        }
        return to_string(abs(a)) + "/" + to_string(abs(b));
    }
    // add c, d to a, b
    // a / b + c / d =>  (a * d + c * b) / (b * d)
    void solve(int &a, int &b, int c, int d) {
        int up = a * d + c * b;
        int down = b * d;
        int gcd = __gcd(up, down);
        a = up / gcd;
        b = down / gcd;
    }
};