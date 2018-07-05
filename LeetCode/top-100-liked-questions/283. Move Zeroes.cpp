class Solution {
public:
    // 双指针
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        int cur = 0;
        int last = 0;
        while(cur < nums.size())
        {
            if(nums[cur] != 0) {
                swap(nums[last],nums[cur]);
                last++;
            }
            cur++;
        }
    }
};