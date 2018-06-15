class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 == 1 && num1[0] == '0') return "0";
        if(len2 == 1 && num2[0] == '0') return "0";
        vector<int> ans(len1+len2, 0);
        string res = "";
        for(int i = len1 - 1; i >= 0; --i) {
            for(int j = len2 - 1; j >= 0; --j) {
                ans[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(int i = len1 + len2 - 1; i >= 1; --i) {
            if(ans[i] >= 10) {
                ans[i-1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }
        
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == 0 && i == 0)continue;
            res += to_string(ans[i]);
        }
        return res;
    }
};