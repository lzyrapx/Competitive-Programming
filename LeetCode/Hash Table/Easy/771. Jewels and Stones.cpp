class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char>s(J.begin(),J.end());
        int ans = 0;
        for(auto c : S)
        {
            if(s.count(c) > 0) {
                ans ++;
            }
        }
        return ans;
    }
};