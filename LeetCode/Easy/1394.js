/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 15:01:15
 */
/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    let mp = []
    for(var i = 0; i < arr.length; i++) {
        if(arr[i] in mp) {
            mp[arr[i]] += 1
        }
        else {
            mp[arr[i]] = 1
        }
    }
    let ans = -1
    for(var x in mp) {
        if(x == mp[x]) {
            ans = Math.max(ans, x)
        }
    }
    return ans
};