class Solution {
public:
    // X is a good number if after rotating each digit individually by 180 degrees
    // we get a valid number that is different from X.
    int rotatedDigits(int N) {
        if(N == 0)return 0;
        map<char,char>mp;
        // rotate to each other
        mp['2'] = '5'; mp['5'] = '2';
        mp['6'] = '9'; mp['9'] = '6';
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            string s = to_string(i);
            string tmp = "";
            for(int j = 0; j < s.size(); j++) {
                // 0, 1, and 8 rotate to themselves
                if(s[j] == '0' || s[j] == '1' || s[j] == '8') tmp = tmp + s[j];
                else if(mp.find(s[j]) != mp.end()) tmp = tmp + mp[s[j]];
                else break;
            }
            if(s.size() == tmp.size() && s != tmp) {
                ans++;
            }
        }
        return ans;
    }
};