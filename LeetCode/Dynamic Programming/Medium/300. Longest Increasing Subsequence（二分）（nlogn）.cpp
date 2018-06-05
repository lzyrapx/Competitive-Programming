class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int sz = nums.size();
        
        if(sz==0)return 0;
        if(sz==1)return 1;
/*
dp storing the smallest tail of all increasing subsequences with length i+1 in dp[i].
len = 1   :      [4], [5], [6], [3]   => dp[0] = 3
len = 2   :      [4, 5], [5, 6]       => dp[1] = 5
len = 3   :      [4, 5, 6]            => dp[2] = 6
维护一个单调递增子序列，它的关键原理在于：
如果当前值小于单调递增子序列中的某个元素，则替换之，
因为单调递增子序列能否增长，值取决于最后一个元素，替换内部的元素并不影响。
dp是满足单调递增的！
例如：
input: [0, 8, 4, 12, 2]
dp: [0]
dp: [0, 8]
dp: [0, 4]
dp: [0, 4, 12]
 */    
        vector<int>dp(sz+1,0);
        int ans = 0;
    
        for(int x : nums)
        {
            int l = 0, r = ans;
            while(l != r)
            {
                int mid = (l + r) >> 1;
                if(dp[mid] < x)
                {
                    l = mid + 1;
                }
                else r = mid;
            }
            dp[l] = x;
            if(l == ans) {
                ans ++;
            }
        }
        return ans;
    }
};