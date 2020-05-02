/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 20:27:16
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var minSubsequence = function(nums) {
    nums.sort((a,b) => b - a);
    let sum = nums.reduce((a, b) => a + b, 0);
    
    let total = 0;
    let i = 0;
    let ans = []
    while(total <= sum / 2) {
        total += nums[i];
        ans.push(nums[i])
        i++;
    }
    return ans;
};