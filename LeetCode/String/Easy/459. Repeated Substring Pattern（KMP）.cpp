class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1) return false;
        if(s.size() == 0) return true;
        
        // fail[k]的含义是s[0~k]这个字符串的后缀可以是前面哪个串(不包含后缀中的字符),,并且是最长的长度
        // fail[k]保存的是下标
        vector<int>fail(s.size()+1,0);
        
        getfail(s,fail);
        
        if(fail[s.size()] == 0) return false;
        
        int diff = s.size() - fail[s.size()];
        //cout << fail[s.size()] << endl;
        string fi = s.substr(0,diff);
        string se = s.substr(fail[s.size()]);
        //cout << "fi = " << fi << endl;
        //cout << "se = " << se << endl;
        if(fi == se) return true;
        else return false;
    }
    void getfail(string p, vector<int>&fail)
    {
        int len = p.size();
        int i = 0, j = -1;
        fail[0] = -1;
        while(i < len)
        {
            while(j != -1 && p[i] != p[j]) {
               j = fail[j];
            }
            i++;
            j++;
            fail[i] = j;
        }
    }
};