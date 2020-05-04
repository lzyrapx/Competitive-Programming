/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-04 12:09:44
 */
/**
 * @param {string} s
 * @return {string}
 */
var reformat = function(s) {
    let letters = []
    let digits = []
    let ans = ''
    for(let ch of s) {
        if('a' <= ch && 'ch' <= 'z') {
            letters.push(ch)
        }
        else {
            digits.push(ch)
        }
    }
    let diff = letters.length - digits.length
    if(Math.abs(diff) >= 2) {
        return ''
    }
    if(diff == 1) {
        digits = digits.concat('')
    }
    if(diff == -1) {
        letters = [''].concat(letters)
    }
    for(let i = 0; i < letters.length; i++) {
        ans += letters[i] + digits[i];
    }
    return ans;
};