class Solution {
public:
    string Symbol[15] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[15] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string intToRoman(int num) {
        string ans = "";
        for(int i = 0; num != 0; i++) {
            while(num >= val[i]){
                num -= val[i];
                ans += Symbol[i];
            }
        }
        return ans;
    }
};