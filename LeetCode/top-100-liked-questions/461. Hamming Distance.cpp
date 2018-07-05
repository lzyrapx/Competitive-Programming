class Solution {
public:
    // 先异或再计算 1 的个数
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int num = 0;
        while(z)
        {
            z = z & (z - 1);
            num++;
        }
        return num;
    }
};