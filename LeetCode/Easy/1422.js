/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-04 14:36:45
 */
/**
 * @param {string} s
 * @return {number}
 */
// 2 <= s.length <= 500
var maxScore = function(s) {
    let zeros = 0; // left - zero
    let ones = 0; // right - one
    for(let i = 1; i < s.length; i++) {
        if(s[i] == '1') {
            ones += 1;
        }
    }
    let ans = 0
    if(s[0] == '1') {
        zeros = 0;
    }
    else {
        zeros = 1;
    }
    ans = ones + zeros;
    for(let i = 1; i < s.length - 1; i++) {
        if(s[i] == '0') {
            zeros++;
        } else {
            ones--;
        }
        ans = Math.max(ans, ones + zeros);
    }
    return ans;
};