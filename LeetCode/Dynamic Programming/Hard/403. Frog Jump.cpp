class Solution {
public:
  
    bool canCross(vector<int>& stones) {
        
        int sz = stones.size();
        if(sz == 0) return false;
        if(sz == 1) return true;
        
        // dp[i][j] 表示 是否能经过 j 步,后 青蛙能跳到石头 stones[i] 处。
       vector<vector<bool>>dp(sz *  2, vector<bool>(sz + 1, false));
       
        dp[0][0] = true;
        // cout << " ok " << endl; 
        for(int i = 1; i < sz; i++)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(stones[i] - stones[j] >= sz) break; //不加约束，会RE
                if(dp[j][stones[i] - stones[j] - 1] == true|| dp[j][stones[i] - stones[j] + 1] == true || dp[j][stones[i] - stones[j]] == true)
                {
                    dp[i][stones[i] - stones[j]] = true;
                }
            }
        }
        // cout << "ok " << endl;
        for(int j = 0; j < sz; j++)
        {
            if(dp[sz-1][j] == true) {
                return true;
            }
        }
        return false;
    }
};