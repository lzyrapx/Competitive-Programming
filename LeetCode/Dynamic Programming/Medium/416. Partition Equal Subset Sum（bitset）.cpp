class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return 0;
        bitset<10001>bit(1);
        for(auto n : nums) {
            bit |= bit << n;
        }
       return bit[sum / 2];      
    }
};

/*
bits的第i位为1的话表示此数组里面存在组合使得该组合的和为i。
此处采用归纳法简单的分析下算法：
1.假设n之前的子列里面存在1~m,k~L……之间和的组合
2.填加了数字n之后，将会存在(1+n)~(m+n),(k+n)~(L+n)……之间和的组合（只要在上面的组合里面添加当前的元素n即可），在标记bits里面相当于将bits向左边移动n位，即bits << n
3.故目前为止，存在1~m,k~L……以及(1+n)~(m+n),(k+n)~(L+n)……之间和的组合
4.故bits |= bits << n
*/