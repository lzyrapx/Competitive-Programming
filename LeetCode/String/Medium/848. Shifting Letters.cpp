class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string ans = "";
        int tmp = 0;
        for(int i = shifts.size() - 1; i >= 0; --i) {
            tmp += shifts[i];
            tmp %= 26;
            S[i] = ((S[i] - 'a') + tmp) % 26 + 'a';
        }
        return S;
    }
};