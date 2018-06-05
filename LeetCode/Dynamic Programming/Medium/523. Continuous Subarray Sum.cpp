class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) { //这题有O(n)的做法，用个map就可以了
        int sz = nums.size();
        if(sz <= 1 ) return 0;

        vector<int>sum(sz+1,0);
        sum[0] = nums[0];
        
        for(int i=1;i<sz;i++)
        {

            if( k != 0 && nums[i] % k == 0 )return 1;
            sum[i] = sum[i-1] + nums[i];
            if(k != 0 && sum[i] % k == 0) return 1;
        }
        if(sum[sz-1] == 0 && k == 0)return 1;
        for(int i=0;i < sz-1;i++)
        {
            for(int j=i+1; j < sz;j++) 
            {
                if(k != 0 && (sum[j]-sum[i]) % k == 0) return 1;
            }
        }
        return 0;
    }
};