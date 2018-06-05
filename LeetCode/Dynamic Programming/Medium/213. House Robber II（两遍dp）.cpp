class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return nums[0];
        if(sz == 2) return max(nums[0],nums[1]);
        if(sz == 3) return max(nums[0],max(nums[1],nums[2]));
        
        int dp1[sz+1]; // dp1[i] : 有要 i
        int dp2[sz+1];// dp2[i] : 没有要 i
            
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        
        dp1[0] = nums[0];
        
        for(int i = 1; i < sz - 1; i++) //选择第一个房子, 不能选择最后一个
        {
            dp1[i] = dp2[i-1] + nums[i];
            dp2[i] = max(dp1[i-1],dp2[i-1]);
        }
        int maxx = max(dp1[sz - 2],dp2[sz - 2]);
        
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        
        dp1[1] = nums[1];
        
        for(int i = 2; i < sz; i++) //不选第一个房子，不选第一个房子的情况下最后一个房子可选可不选
        {
            dp1[i] = dp2[i-1] + nums[i];
            dp2[i] = max(dp1[i-1],dp2[i-1]);
        }
        int maxxx = max(dp1[sz - 1], dp2[sz - 1]);
        return max(maxx,maxxx);
    }
};