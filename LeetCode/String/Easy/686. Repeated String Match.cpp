class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        for(int times = 1; times <= B.size() / A.size() + 2; times ++) {
            if(t.find(B) != string::npos) return times;
            t = t + A;
        }
        return -1;
    }
};