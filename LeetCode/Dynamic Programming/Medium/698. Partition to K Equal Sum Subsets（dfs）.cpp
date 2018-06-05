class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(k <= 0 || sum % k != 0) return 0;
        vector<int> vis(nums.size(),0);
        return dfs(nums,vis,0,k,0,0,sum / k);
    }
    int dfs(vector<int>&nums,vector<int>&vis,int st,int k,int cur_sum,int cur_num,int target)
    {
        if(k == 1) return 1;
        if(cur_sum == target && cur_sum > 0) {
            return dfs(nums,vis,0,k-1,0,0,target);
        }
        for(int i=st;i<nums.size();i++)
        {
            if(vis[i]== 0){
                vis[i] = 1;
                if(dfs(nums,vis,i + 1, k, cur_sum + nums[i],cur_num +1 ,target)) {
                    return 1;
                }
                vis[i] = 0;
            }
            
        }
        return 0;
    }
};