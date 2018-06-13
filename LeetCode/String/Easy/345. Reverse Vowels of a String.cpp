class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0) return "";
        if(s.size() == 1) return s;
        string ans = "", tmp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u')
            {
                tmp = tmp + s[i];
            }
            else if(s[i] == 'A' || s[i] == 'I' || s[i] == 'O' || s[i] == 'E' || s[i] == 'U')
            {
                tmp = tmp + s[i];
            }
        }
        reverse(tmp.begin(), tmp.end());
        //cout << tmp << endl;
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u')
            {
                s[i] = tmp[j++];
                
            }
            else if(s[i] == 'A' || s[i] == 'I' || s[i] == 'O' || s[i] == 'E' || s[i] == 'U')
            {
                s[i] = tmp[j++];
            }
        }
        return s;
    }
};