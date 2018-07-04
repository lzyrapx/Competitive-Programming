class Solution {
public:
    // 双指针
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int left = 0, right = height.size() - 1;
        int area = 0;
        while(left < right)
        {
            int l = height[left];
            int r = height[right];
            if(height[left] < height[right]) {
                while(left < right && l >= height[++left]) { // 前高后低
                    area += (l - height[left]);
                    // cout << "left : " <<  l - height[left] << endl;
                }
            }
            else {
                while(left < right  && r >= height[--right]) { // 前低后高
                    area += (r - height[right]);
                    // cout << "right : " << r - height[right] << endl;
                }
            }
        }
        return area;
    }
};