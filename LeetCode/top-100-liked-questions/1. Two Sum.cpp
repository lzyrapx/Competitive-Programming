class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int>mp;
        vector<int>v;
        for(int i = 0;i<nums.size();i++)
        {
            int nxt = target - nums[i];
            if(mp.find(nxt)!=mp.end()) 
            {
                v.push_back(mp[nxt]);
                v.push_back(i);
                return v;
            }
            mp[nums[i]] = i;
            
        }
    }
};
