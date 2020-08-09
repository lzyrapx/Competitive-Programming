class Solution {
public:
    string makeGood(string s) {
        if(s.size() == 0){
            return "";
        }
        string ans;
        for(auto c: s) {
            if(ans.size() > 0 && (abs(c - ans.back()) == ('a' - 'A'))) {
                ans.pop_back();
            } else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};