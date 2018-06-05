class Solution {
public:
    int findIntegers(int num) { //二进制中不能连续两个一的方案数
        if(num == 0) return 1;
        int len = 0;
        int n = num;
        string s = "";
        while(n)
        {
            len++;
            s += (n & 1) ? "1" : "0";
            n >>= 1;
        }
        vector<int>one(len + 1, 0);
        vector<int>zero(len + 1,0);
        zero[0] = 1; one[0] = 1;
        for(int i = 1; i < len; i++)
        {
            zero[i] = zero[i-1] + one[i-1]; //前一位是 0 或 1的话,当前位只能为 0
            one[i] = zero[i-1]; //前一位是 0 的话,当前位可以为 1
        }
        int ans = zero[len - 1] + one[len - 1];
        for(int i = len - 2; i >= 0; --i)
        {
            if(s[i] == '1' && s[i+1] =='1') break;
            if(s[i] =='0' && s[i+1] =='0'){
                ans -= one[i];
            }
        }
        return ans;
    }
};