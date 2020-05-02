/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 16:17:31
 */
/**
 * @param {number} n
 * @return {number}
 */
var countLargestGroup = function(n) {
    let sum = 0
    let tmp = 0
    const map = new Map()
    
    for(let i = 1; i <= n; i++) {
        sum = 0;
        tmp = i;
        while(tmp) {
            sum += tmp % 10;
            tmp = Math.floor(tmp / 10);
        }
        map.set(sum, (map.get(sum) || 0) + 1);
    }
    let val = 0;
    let ans = 0;
    for(let v of map.values()) {
        if(v > val) {
            val = v;
            ans = 1;
        }
        else if(v == val) {
            ans += 1;
        }
    }
    return ans;
};