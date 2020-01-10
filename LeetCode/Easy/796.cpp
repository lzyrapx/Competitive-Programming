/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-10 23:33:15
 */
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) {
            return false;
        }
        string C = A + A;
        if(C.find(B) != string::npos) return true;
        return false;
    }
};