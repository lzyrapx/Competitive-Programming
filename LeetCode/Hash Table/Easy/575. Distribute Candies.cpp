class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s(candies.begin(),candies.end()); 
        return min((int) candies.size() / 2,(int) s.size());
    }
};