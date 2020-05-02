/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 22:43:16
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
// 1 <= words.length <= 100
// 1 <= words[i].length <= 30
// words[i] contains only lowercase English letters.

// 这题也可以用 trie 吧...但不想写了...反正数据量这么少...
var stringMatching = function(words) {
    let ans = []
    var tmp = "";
    for(let i = 0; i < words.length; i++){
        tmp = words[i];
        for(let j = 0; j < words.length; j++) {
            if(i != j && words[j].includes(words[i])) {
                ans.push(words[i])
                break;
            }
        }
    }
    return ans;
};