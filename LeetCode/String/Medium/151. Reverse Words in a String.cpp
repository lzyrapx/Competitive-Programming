class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0) return;
        stringstream ss(s);
        string word, ans;
        while(ss >> word) {
            // cout << word << endl;
            if(ans.size() != 0) {
                word = word + " ";
            }
            ans = word + ans;
            // cout << ans << endl;
        }
        s = ans;
    }
};