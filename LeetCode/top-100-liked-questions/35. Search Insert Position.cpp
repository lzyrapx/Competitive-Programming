class Solution {
public:
    // beats 98.67 %
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] < target) {
                low = mid + 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] == target){
                return mid;
            }
        }
        return low;
    }
};