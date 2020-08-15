class Solution {
public:
    // 题意：给你一个数字字符串，从这串数字里移掉 k 个 数字，使得数字最小
    // 可以有前缀零
    // 思路：从左到右，找第一个比后面大的字符，删除，清零，k次扫描。
    string removeKdigits(string num, int k) {
        if(num.size() == k) {
            return "0";
        }
        for(int i = 0; i < k; i++) {
            int idx = 0;
            for(int j = 1; j < num.size() && num[j] >= num[j - 1]; j++) {
                idx = j;
            }
            num = num.substr(0, idx) + num.substr(idx + 1);
            while (num.size() > 1 && num[0] == '0') {
                num = num.substr(1);
            }
        }
        return num;
    }
};