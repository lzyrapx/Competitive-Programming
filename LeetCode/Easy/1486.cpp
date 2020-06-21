/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-22 00:17:00
 */ 
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans ^=  (start + 2 * i);
        }
        return ans;
    }
};