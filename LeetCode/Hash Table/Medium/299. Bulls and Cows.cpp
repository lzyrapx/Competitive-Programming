class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        map<int,int>mp;
        int n = secret.size();
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) bull++;
            mp[secret[i]]++;
        }
        for(auto ch: guess) {
            if(mp[ch] > 0) {
                mp[ch]--;
                cow++;
            }
        }
        cow -= bull;
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};