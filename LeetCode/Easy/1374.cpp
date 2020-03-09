/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-08 23:58:22
 */
class Solution {
public:
    // each character in such string occurs an odd number of times.
    // 1 <= n <= 500
    string generateTheString(int n) {
        string ans;
        if(n == 1) {
            return "a";
        }
        cout << string(n, 'a') << endl;
        if(n % 2 == 1) {
            ans = string(n, 'a');
        }
        else ans = string(1, 'a') + string(n - 1, 'b');
        return ans;
    }
};