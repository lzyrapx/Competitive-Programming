class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(),str.end());
        int last = 0;
        for(int i = 0; i <= str.size(); i++) {
            if(i == str.size() || str[i] == ' '){
                reverse(str.begin() + last, str.begin() + i);
                last = i + 1;
            }
        }
        return str;
    }
};