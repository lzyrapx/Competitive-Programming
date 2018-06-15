class Solution {
public:
    string toGoatLatin(string S) {
        
        string ans = "";
        string word = "";
        
        set<char>se{'a','e','i','o','u','A','E','I','O','U'};
        
        int i = 0, j = 1;
        int cnt = 0;
        
        while(i < S.size()) 
        {
            if(S[j] == ' ' || j == S.size()) 
            {
                cnt++;
                word = S.substr(i,j - i);
                if(se.count(word[0]) == 0) { //首字母非元音,第二种情况
                    word = word.substr(1,word.size()-1) + word[0] + "ma";
                    for(int k = 1; k <= cnt; k++) { // 第三种
                        word = word + 'a';
                    }
                }
                else { //首字母元音,第一种
                    word = word + "ma";
                    for(int k = 1; k <= cnt; k++) { // 第三种
                        word = word + 'a';
                    }
                }
                ans = ans + word + " ";
                i = j + 1;
                j = i + 1;
            }
            else {
                j++;
            }
        }
        
        // cout << ans << endl;
        ans = ans.substr(0,ans.size()-1);
        return ans;
    }
};