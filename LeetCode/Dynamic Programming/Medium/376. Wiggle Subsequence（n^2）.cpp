class Solution {
public:
int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz==0)return 0;
        std::vector<int> dp1(nums.size()+1,0);//+
        std::vector<int> dp2(nums.size()+1,0);//-


        for(int i=1;i<sz;i++) {
          for(int j=0;j<i;j++) {
            if(nums[j] - nums[i] > 0) {
              dp1[i] = max(dp1[i],dp2[j]+1);
            }
            else if(nums[j] - nums[i] < 0) {
              dp2[i]=max(dp2[i],dp1[j]+1);
            }
          }
        }
        // std::cout << dp1[sz-1] << '\n';
        // std::cout << dp2[sz-1] << '\n';
        return max(dp1[sz-1],dp2[sz-1])+1;
    }
};