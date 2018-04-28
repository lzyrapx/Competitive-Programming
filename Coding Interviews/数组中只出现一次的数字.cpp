class Solution {
public:
    /*
     用位运算实现，如果将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或
     的结果。在结果数字中找到第一个为1的位的位置，记为第 id 位。
     现在我们以第 id 位是不是 1 为标准把原数组中的数字分成两个子数组，第一个子数组中每个数字的第 id 位都为 1，
     而第二个子数组的每个数字的第 id 位都为0。(这两个数字不同，意味着为1的那个位是相异的)。
    */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        int tmp = data[0];
        for(int i = 1; i < data.size(); i++)
        {
            tmp = tmp ^ data[i];
        }
        if(tmp == 0) return ;
        int id = 0;
        // 异或结果位出现 1 说明原来两个数在该位上是相异的
        while((tmp & 1) == 0) {
            tmp >>= 1;
            id++;
        }
        // 把数组分成两组
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if((data[i] >> id) % 2 == 1) *num1 ^= data[i];
            else *num2 ^= data[i];
        }
    }
};