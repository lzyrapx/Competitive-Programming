/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 23:37:10
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var minStartValue = function(nums) {
    let ans = 0
    let sum = 0
    for(let i = 0; i < nums.length; i++) {
        sum += nums[i]
        if(sum < 1) {
            ans = Math.max(ans, 1 - sum);
        }
    }
    if(ans == 0){
        return 1;
    }
    else {
        return ans;
    }
};