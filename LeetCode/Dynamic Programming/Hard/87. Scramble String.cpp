class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(s1 == s2) return 1;
        if(m != n) return 0;
        string tmp_s1 = s1, tmp_s2 = s2;
        sort(tmp_s1.begin(),tmp_s1.end());
        sort(tmp_s2.begin(),tmp_s2.end());
        if(tmp_s1 != tmp_s2) return 0;
        for(int i = 1; i < s1.size(); i++)
        {
            string s11 = s1.substr(0,i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0,i);
            string s22 = s2.substr(i);
            if(isScramble(s11,s21) == 1 && isScramble(s12,s22) == 1){
                return 1;
            }
            s21 = s2.substr(s2.size() - i);
            s22 = s2.substr(0,s2.size() - i);
            if(isScramble(s11,s21) == 1 && isScramble(s12,s22) == 1)
            {
                return 1;
            }
        }
        return 0;
    }
};