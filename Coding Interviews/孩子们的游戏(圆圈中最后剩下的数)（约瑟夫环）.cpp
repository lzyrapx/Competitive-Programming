class Solution {
public:
    // 约瑟夫环
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0) return -1;
        int s = 0;
        for(int i = 2; i <= n; i++){
            s = (s + m) % i;
        }
        return s;
    }
};