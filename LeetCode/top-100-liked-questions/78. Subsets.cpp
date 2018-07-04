class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size() == 0) return ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < (1 << n); i++) 
        {
            vector<int>tmp;
            for(int j = 0; j < n; j++) 
            {
                if(i & 1 << j) 
                {
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};