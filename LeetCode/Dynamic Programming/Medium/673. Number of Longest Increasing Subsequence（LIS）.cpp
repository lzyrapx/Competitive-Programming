class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() <2) return nums.size();
        int sz = nums.size();
        int maxlen = 1;
        int ans = 0;
        std::vector<int> cnt(sz,1); // cnt[i] 表示 以 nums[i] 结尾的 最长递增不连续序列 的个数
        std::vector<int> len(sz,1); //len[i] 表示 以 nums[i] 结尾的 最长递增不连续序列 的长度
        for(int i=1;i<sz;i++)
        {
          for(int j=0;j<i;j++)
          {
            if(nums[j] < nums[i])
            {
              if(len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                cnt[i] = cnt[j];
              }
              else if(len[j] + 1 == len[i]) {
                cnt[i] +=  cnt[j];
              }
            }
          }
          maxlen = max(maxlen,len[i]);
        }
        for(int i=0;i< sz;i++) {
          if(len[i] == maxlen) {
            ans += cnt[i];
          }
        }
        return ans;
    }
};