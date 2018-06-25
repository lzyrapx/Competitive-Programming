class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int n = sqrt(c);
        for(int i = 0; i <= n; i++) {
            int b = c - i * i;
            if(sqrt(b) == (int)sqrt(b)) return true;
        }
        return false;
    }
};