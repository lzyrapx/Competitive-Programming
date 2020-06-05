/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-05 23:35:08
 */ 
class Solution {
public:
    // [0] : 0
    // [0, 1]: [0, 2^0]
    // [0, 1, 3, 2]: [0, 1, 1 + 2^1, 0 + 2^1]
    vector<int> grayCode(int n) {
        int shift = 0;
        vector<int>res;
        while(n >= 0) {
            if(res.size() == 0) {
                res.push_back(0);
            }
            else {
                for(int i = res.size() - 1; i >= 0; --i) {
                    res.push_back(res[i]  +  (1 << shift));
                }
                shift++;
            }
            n--;
        }
        return res;
    }
};