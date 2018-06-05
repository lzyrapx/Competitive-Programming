class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();
        
        //按照降序排序, 所以nums[i] < nums[j] (j < i ),并且之前能够被nums[j]整除的数, 也必然能够别nums[i]整除
        //保证了状态转移方程的正确性. 
        sort(nums.begin(),nums.end(),greater<int>()); //降序
        
        int sz = nums.size();
        
        int cur_max = 1;
        
        int k = 0;
        
        vector<int>fa(sz+1,0);
        
        vector<int>dp(sz+1,1);
        
        vector<int>ans;
        
        for(int i = 0; i < sz; i++)
        {
            fa[i] = i;
        }
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] % nums[i] == 0)
                {
                    //要求找出最大结果, 所以我们还需要记录一下路径, 每一个数字
                    //记录一个第一个能够使其到达最大长度的父结点, 最后回溯一下即可
                   if(dp[i] < dp[j] + 1)
                   {
                       dp[i] = dp[j] + 1;
                       fa[i] = j;
                   }
                   
                   if(dp[i] > cur_max)
                   {
                       cur_max = dp[i];
                       k = i;
                   }
                }
            }
        }
        while(fa[k] != k)
        {
            ans.push_back(nums[k]);
            k = fa[k];
        }
        ans.push_back(nums[k]);
        return ans;
    }
};