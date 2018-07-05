class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        if(s.size() == 0) return ans;
        stack<string>str;
        stack<int>nums;
        int num = 0;
        for(char ch: s)
        {
            if(isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            else if(isalpha(ch))
            {
                ans.push_back(ch);
            }
            else if(ch =='[')
            {
                str.push(ans);
                ans = "";
                nums.push(num);
                num = 0;
                
            }
            else if(ch == ']')
            {
                string tmp = ans;
                for(int i = 0; i < nums.top() - 1; i++) {
                    ans += tmp;
                }
                ans = str.top() + ans;
                str.pop();
                nums.pop();
            }
        }
        return ans;
    }
};