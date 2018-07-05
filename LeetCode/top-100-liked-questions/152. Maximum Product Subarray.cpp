class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int sz = nums.size();
        if(sz <= 1)return nums[0];
        int ans = 0;
        int Max = 1, Min = 1;
        for(int i = 0; i < sz ; i++) 
        {
            if(nums[i] < 0) {
                swap(Max,Min);
            }
            Max = max(nums[i], Max * nums[i]);
            Min = min(nums[i], Min * nums[i]);
            
            ans = max(Max,ans);
        }
        return ans;
    }
};