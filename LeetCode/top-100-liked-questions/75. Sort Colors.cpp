class Solution {
public:
    // 要求空间 O(1)
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return;
        int low = 0; // 0的位置
        int high = nums.size() - 1; // 1的位置
        int i = 0;
        while(low <= high && i <= high)
        {
            if(nums[i] == 2) {
                swap(nums[i],nums[high]);
                high--;
            }
            else if(nums[i] == 0)
            {
                swap(nums[i],nums[low]);
                low++;
                i++;
            }
            else if(nums[i] == 1) {
                i++;
            }
        }
    }
};