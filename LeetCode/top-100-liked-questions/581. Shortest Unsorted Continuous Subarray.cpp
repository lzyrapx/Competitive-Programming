class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int>t = nums;
        sort(t.begin(),t.end());
        if(nums == t) return 0;
        while(i < j && t[i] == nums[i]) i++;
        while(i < j && t[j] == nums[j]) j--;
        return j - i + 1;
    }
};