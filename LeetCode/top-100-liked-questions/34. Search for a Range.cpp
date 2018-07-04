class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();
        if(n == 0) return  vector<int>{-1,-1};
        if(n == 1) {
            if(nums[0] == target) {
                return vector<int>{0,0};
            }
            return vector<int>{-1,-1};
        }
        int left = 0, right = 0; // 记录答案的区间
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] >= target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) { // 严格递增
                low = mid + 1;
            }
        }
        left = low;
        
        low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] > target) {  // 严格递增
                high = mid - 1;
            }
            else if(nums[mid] <= target) { 
                low = mid + 1;
            }
        }
        right = low;
        
        if(left == right) {
            return vector<int>{-1,-1};
        }
        else {
            ans.push_back(left);
            ans.push_back(right-1);
        }
        return ans;
    }
};