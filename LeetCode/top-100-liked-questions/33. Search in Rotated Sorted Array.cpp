class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) {
            if(target == nums[0]) return 0;
            else return -1;
        }
        int n = nums.size();
        int low = 0, high = n - 1; 
        // 先二分出分割点
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[low] > nums[mid])
            {
                high = mid - 1;
            }
            else if(nums[low] < nums[mid]) {
                low = mid;
            }
            else if(nums[low] == nums[mid]) {
                if(nums[low] < nums[high]) low = high;
                break;
            }
        }
        int idx = low;
        // 0~idx, idx+1~n-1 are two sorted arrays
        if(target >= nums[0]) // 在前一个有序数组
        {
            low = 0, high = idx;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return -1;
        }
        else { // 在后一个有序数组
            low = idx + 1;
            high = n - 1;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return -1;
        }
    }
};