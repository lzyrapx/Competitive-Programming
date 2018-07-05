class Solution {
public:
    // 这个做法其实是O(n+n) = O(n)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        set<int>se(nums.begin(),nums.end());
        int max_len = 0;
        for(auto x : se)
        {
            if(se.count(x - 1) == 0)
            {
                int len = 1;
                while(se.count(x + 1)) {
                    len++;
                    x++;
                }
                max_len = max(max_len,len);
            }
        }
        return max_len;
    }
};