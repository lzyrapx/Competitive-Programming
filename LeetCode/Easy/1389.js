/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 14:47:18
 */
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    let target = []
    for(var i = 0; i < nums.length; i++) {
        target.splice(index[i], 0, nums[i])
    }
    return target
};