/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 18:24:12
 */
class Solution {
public:
    // only swap one time
    bool buddyStrings(string A, string B) {
        
        set<int>se;
        if(A == B) {
            // ab => false 
            // aa => true 
            // abab => true
            // abcd => false
            for(int i = 0; i < A.size(); i++) {
                se.insert(A[i]);
            }
            if(se.size() == A.size() && se.size() > 1) return false;
            if(se.size() >= 2 && A.size() > 2) return true;
            if(se.size() == 1 && A.size() >= 2) return true;
            return false;
        }
        if(A.size() != B.size()) {
            return false;
        }
        int l = 0, r = A.size() - 1;
        while(l < A.size() && A[l] == B[l]) {
            l++;
        }
        while(r >= 0 && A[r] == B[r]) {
            r--;
        }
        if(l < r) {
            swap(A[l], A[r]);
        }
        return A == B;
    }
};