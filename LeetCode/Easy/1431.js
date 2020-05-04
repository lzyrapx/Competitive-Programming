/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-04 12:16:58
 */
/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let max_val = -1
    for(let i = 0; i < candies.length; i++) {
        max_val = Math.max(candies[i], max_val)
    }
    let ans = []
    for(let i = 0; i < candies.length; i++) {
        if(extraCandies + candies[i] < max_val) {
            ans.push(false)
        }
        else {
            ans.push(true)
        }
    }
    return ans
};