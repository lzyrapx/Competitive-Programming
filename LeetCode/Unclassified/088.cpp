/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 17:14:14
 */
class Solution {
public:
    // 合并有序数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m - 1, b = n - 1;
        int i = m + n - 1;
        while(a >= 0 && b >= 0) {
            if(nums1[a] > nums2[b]) {
                nums1[i--] = nums1[a--];
            }
            else {
                nums1[i--] = nums2[b--];
            }
        }
        // if nums2 is longer than nums1
        while(b >= 0) {
            nums1[i--] = nums2[b--];
        }
    }
};