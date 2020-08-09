class Solution {
public:
    // 1. 从右到左，只有奇数时才会消除第一个
    // 2. 每次都会消掉一半
    int lastRemaining(int n) {
        int remain = n;
        int flag = 1;
        int num = 1; // 可以理解为每次新序列的第一个数字
        int step = 1;
        while(remain > 1) {
            // 从左到右 or 剩余个数为奇数 
            if(flag || remain % 2 == 1) {
                num += step; 
            }
            flag = !flag;
            step *= 2;
            remain /= 2;
        }
        return num;
    }
};