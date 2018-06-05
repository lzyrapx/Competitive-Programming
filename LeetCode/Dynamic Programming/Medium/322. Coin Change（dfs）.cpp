class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0) return 0;
        int m = coins.size();
        int ans = -1;
        vector<int>cnt(amount+1,0);
        ans = dfs(coins,amount,cnt);
        if(ans == INT_MAX) return -1;
        else return ans;
        return ans;
    }
    int dfs(vector<int>& coins,int remain, vector<int>& cnt)
    {
        if(remain < 0) return -1;
        if(remain == 0) return 0;
         // cout << "remain=" << remain << endl;
        if(cnt[remain] != 0) return cnt[remain]; //记忆化

        int minn = INT_MAX;
        for(int i = 0;i < coins.size(); i++) 
        {
            int num = dfs(coins,remain - coins[i], cnt);
            if(num >= 0 && num < minn)
            {
                minn = num + 1;
            }
        }

        cnt[remain] = (minn == INT_MAX ? -1 : minn);
        return cnt[remain];
    }
};