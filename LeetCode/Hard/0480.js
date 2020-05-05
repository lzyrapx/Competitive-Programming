/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-04 16:06:00
 */
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var medianSlidingWindow = function(nums, k) {
    if(nums.length == 0) {
        return []
    }
    let window = nums.slice(0, k);
    let mid_val = find_median(window)
    let ans = []
    ans.push(mid_val)
    for(let i = k; i < nums.length; i++) {
        window = nums.slice(i - k + 1, i + 1);
        // console.log("i = ", i, nums)
        ans.push(find_median(window))
    }
    return ans
};

let find_median = function(window) {
    window.sort((a, b) => a - b)    
    let n = window.length
    mid = window[Math.floor(n / 2)]
    if(n & 1 == 1) {
        return mid
    }
    else {
        return (Math.floor(window[Math.floor((n - 1) / 2)]) + mid) / 2;
    }
}