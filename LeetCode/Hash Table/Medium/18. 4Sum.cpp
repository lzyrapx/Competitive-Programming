class Solution {
public:
    // 在3sum的基础上做4sum
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) return ans;
            
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;
        int target_3Sum = 0, target_2Sum = 0;
        
        for(int i = 0; i < n - 3; i++)
        {
            if (i != 0 && nums[i] == nums[i-1]) continue; 
            target_3Sum = target - nums[i];
            
            // 3Sum Problem
            for(int j = i + 1; j < n-2; j++)
            {
                if(j != (i + 1) && nums[j] == nums[j-1]) continue;
                target_2Sum = target_3Sum - nums[j];
                left = j + 1;
                right = n - 1;
                while(left < right)
                {
                    if(nums[left] + nums[right] == target_2Sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        
                        while(left < right && nums[left+1] == nums[left]) ++left;
                        while(left < right && nums[right-1] == nums[right]) --right;    
                        ++left;
                        --right;
                    }
                    else if(nums[left] + nums[right] < target_2Sum) {
                         ++left;
                    } 
                    else --right;
                }
            }
        }
        return ans;
    }
};
