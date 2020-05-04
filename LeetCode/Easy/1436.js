/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-04 14:46:03
 */
/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function(paths) {
    let start = paths.map(path => path[0])
    let end = paths.map(path => path[1])
    for(let e of end) {
        if(start.indexOf(e) == -1) {
            return e
        }
    }
    return ""
    
};