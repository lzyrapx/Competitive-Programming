/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 20:34:10
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>hash(n, 0);
        // hash[i]存放第i个单词出现过的字母, 
        // a对应32位整数的最后一位, b对应整数的倒数第二位, 依次类推
        for(int i = 0; i < n; i++) {
            for(char c: words[i]) {
                hash[i] |= 1 << (c - 'a');
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((hash[i] & hash[j]) == 0) {
                    ans = max(ans, int(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};