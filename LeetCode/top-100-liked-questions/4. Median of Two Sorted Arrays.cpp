class Solution {
public:
    // 数据已经有序
    // O(log (m+n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size() > nums2.size())) {
            return findMedianSortedArrays(nums2,nums1);
        }
        // sz1 <= sz2
        int sz1= nums1.size();
        int sz2 = nums2.size();
        int low = 0 , high = sz1;
        int mid = 0;
        int i = 0;
        // 将原问题转换为一个寻找第k小数的问题
        int a, b;
        while(low <= high)
        {
            mid = (low + high) >> 1; // 对nums1二分
            i = (sz1 + sz2 + 1.0) / 2 - mid;
            if(mid > 0 && i < sz2 && nums1[mid - 1] > nums2[i]) {
                high = mid - 1;
            }
            else if(mid < sz1 && i > 0 && nums1[mid] < nums2[i - 1]) {
                low = mid + 1;
            }
            else {
                if(mid == 0) {
                    a = nums2[i - 1];
                }
                else if(i == 0) {
                    a = nums1[mid - 1];
                }
                else {
                    a = max(nums1[mid - 1], nums2[i - 1]);
                }
                break;
            }
        }
        // odd
        if((sz1 + sz2) % 2 == 1) {
            return a;
        }
        else { // even
            if(mid == sz1) {
                b = nums2[i];
            }
            else if(i == sz2) {
                b = nums1[mid];
            }
            else {
                b = min(nums1[mid], nums2[i]);
            }
            return (a + b) / 2.0;
        }
    }
};