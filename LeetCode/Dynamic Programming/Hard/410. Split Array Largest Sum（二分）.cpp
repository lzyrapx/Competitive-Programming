class Solution {
public:
    typedef long long ll;
    int split(vector<int>&nums,int m, int sum)
    {
        
        int cnt = 1;
        ll cur_sum = 0;
        for(int i = 0; i < nums.size();i++ )
        {
            cur_sum += nums[i];
            if(cur_sum > sum)
            {
                cur_sum = nums[i];
                cnt++;
                if(cnt > m) return 0;
             }
                
        }
        return 1; //无法分为3组
    }
    int splitArray(vector<int>& nums, int m) {
        ll right = 0, left = 0;
        int sz = nums.size();
        if(sz == m) {
            ll ans = 0;
            for(auto x :nums)
            {
               ans = max(ans,1LL*x);
            }
            return ans;
        }
        if(m == 1) {
            ll ans = accumulate(nums.begin(),nums.end(),0);
            return ans;
        }
        for(auto x : nums){
            left = max(left,1LL*x);
        }
        
        right = accumulate(nums.begin(),nums.end(),0);
        
        while(left < right)
        {
            ll mid = (left + right) >> 1;
            if(split(nums,m,mid)) { 
                right = mid;  //无法分为3组, 缩小mid
            }
            else left = mid + 1;
        }
        return left;
    }
};