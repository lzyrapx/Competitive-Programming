class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int cnt = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(cnt == 0 && s[i] == ' ') {
                continue;
            }
            if(s[i] == ' ') break;
            cnt++;
        }
        return cnt;
    }
};