class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        if(nums.size() == 3) return nums[0] * nums[1] * nums[2];
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int a = nums[n-1] * nums[n-2] * nums[n-3];
        int b = nums[0] * nums[1] * nums[n-1];
        return max(a,b);
    }
};