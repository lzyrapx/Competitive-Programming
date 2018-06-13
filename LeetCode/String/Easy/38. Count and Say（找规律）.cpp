class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        if(n == 2) {
            return "11";
        }
        if(n == 3) {
            return "21";
        }
        string ans = "1";
        for(int i = 1; i < n; i++) {
            ans = getNext(ans);
        }
        return ans;
    }
    string getNext(string s)
    {
        string ans = "";
        int cnt = 1;
        for(int i = 0; i < s.size(); i++) {
            while(i + 1 < s.size() && s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + s[i];
            cnt = 1;
        }
        return ans;
    }
};