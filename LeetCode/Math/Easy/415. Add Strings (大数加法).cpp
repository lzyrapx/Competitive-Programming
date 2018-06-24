class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int x1 = 0, x2 = 0;
        for(int i = num1.size() -1, j = num2.size() -1; i >= 0 || j >= 0 || carry ; --i, --j)
        {
            if(i >= 0) {
                x1 = num1[i] - '0';
            }
            else x1 = 0;
            if(j >= 0) {
                x2 = num2[j] - '0';
            }
            else x2 = 0;
            // cout << x1 << " " << x2 << endl;
            ans = (char)((x1 + x2 + carry) % 10 + '0') + ans;
            carry = (x1 + x2 + carry) / 10;
        }
        return ans;
    }
};