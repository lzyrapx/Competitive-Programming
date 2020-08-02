/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 13:19:08
 */ 
class Solution {
public:
    // nums[0] < nums[1] > nums[2] < nums[3]...
    void wiggleSort(vector<int>& nums) {
        vector<int>tmp(nums);
        sort(tmp.begin(), tmp.end());
        int end = nums.size() - 1;
        int mid = (nums.size() + 1) / 2 - 1;
        for(int i = 0; i < tmp.size(); i++) {
            if(i % 2 == 0) {
                nums[i] = tmp[mid--];
            }
            else {
                nums[i] = tmp[end--];
            }
        }
    }
};