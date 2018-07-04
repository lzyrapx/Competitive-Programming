class Solution {
public:
    // contains the most water.
    // 双指针
    // 容器高度较大的一侧的移动只会造成容器盛水量减小,，所以移动高度较小的一侧
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while(i < j)
        {
            if(height[i] < height[j])
            {
                ans = max((j - i) * height[i], ans);
                i++;
            }
            else if(height[i] >= height[j])
            {
                ans = max((j - i) * height[j], ans);
                j--;
            }
        }
        return ans;
    }
};