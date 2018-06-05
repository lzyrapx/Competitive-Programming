class Solution {
public:
   int cnt = 0;
    void dfs(vector<int>& nums,int i,int sum,int S)
    {

   // std::cout << nums.size() << '\n';
    if(i==(int)nums.size()) {
    // std::cout << "sum=" << sum << '\n';
        if(sum==S) {
        cnt ++;
        }
    }
    else {
        dfs(nums,i+1, sum+nums[i],S);
        dfs(nums,i+1,sum-nums[i],S);
    }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sz = nums.size();
        std::vector<std::vector<int>> dp(sz+1,std::vector<int>(2,0));
        dfs(nums,0,0,S);
        return cnt;
  }
};