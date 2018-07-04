class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ans;
        int n = nums.size();
        if(n < 3) return ans;
        sort(nums.begin(),nums.end());
        int left = 0, right = 0;
        int target = 0;
        
        for(int i = 0; i < n - 2; i++) 
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            target = nums[i];
            left = i + 1;;
            right = n - 1;
            while(left < right)
            {
                if(nums[right] < 0) break;
                if(nums[left] + nums[right] + target == 0)
                {
                    vector<int>tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ans.push_back(tmp);
                    while(left < right && nums[left + 1] == nums[left]){
                        left++;
                    }
                     while(left < right && nums[right - 1] == nums[right]){
                        right--;
                    }
                    left++; right--;
                }
                else if(nums[left] + nums[right] + target < 0) {
                    left++;
                }
                else right--;
            }
        }
        return ans;
    }
};