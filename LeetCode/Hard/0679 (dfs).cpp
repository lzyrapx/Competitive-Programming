/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-10 23:10:35
 */
class Solution {
public:
    // *, /, +, -, (, ) to get the value of 24.
    bool judgePoint24(vector<int>& nums) {
       vector<double> ve{double(nums[0]), double(nums[1]), double(nums[2]), double(nums[3])};
        return dfs(ve, 4);
    }
    bool dfs(vector<double>&nums, int n) {
        if(n == 1) {
            if(fabs(nums[0] - 24) < 0.00001) {
                return true;
            }
        }
        double a = 0.0;
        double b = 0.0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                a = nums[i];
                b = nums[j];

                nums[j] = nums[n - 1]; // num[j] 被消掉了，用最后的指替换当前 num[j]的位置...
                
                nums[i] = a + b;
                if(dfs(nums, n - 1)) return true;
                nums[i] = a - b;
                if(dfs(nums, n - 1)) return true;
                nums[i] = b - a;
                if(dfs(nums, n - 1)) return true;
                nums[i] = a * b;
                if(dfs(nums, n - 1)) return true;
                nums[i] = a / b;
                if(dfs(nums, n - 1)) return true;
                nums[i] = b / a;
                if(dfs(nums, n - 1)) return true;
                
                nums[i] = a;
                nums[j] = b;
            }
        }
        return false;
    }
};