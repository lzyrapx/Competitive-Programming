class Solution {
public:
   // Given a string containing only three types of characters: '(', ')' and '*', 
    // write a function to check whether this string is valid. 
    bool checkValidString(string s) {
        if(s.size() == 0) return true;
        int min_left = 0;
        int max_left = 0;
        for(int i = 0 ; i < s.size(); i++) 
        {
            if(s[i] == '(')
            {
                min_left++;
                max_left++;
            }
            else if(s[i] == ')')
            {
                min_left --;
                max_left --;
            }
            else if(s[i] == '*')
            {
                min_left --;
                max_left ++;
            }
            if(min_left < 0 && max_left < 0) {
                return false;
            }
            else if(min_left < 0)
            {
                min_left = 0;
            }
        }
        if(min_left == 0) return true;
        else return false;
    }
};