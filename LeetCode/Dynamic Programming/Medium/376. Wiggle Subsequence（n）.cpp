int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz==0)return 0;
        if(sz==1)return 1;
        int up = 1;
        int down = 1;
        for(int i=1;i<(int)sz;i++) {
          if(nums[i] - nums[i-1] > 0) {
            up = down + 1;
          }
          else if(nums[i] - nums[i-1] < 0) {
            down = up +1;
          }
        }
        return max(down,up);
    }