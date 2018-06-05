class Solution {
public:
    // dp[i]表示组成第i个子集合所需要的最少的sticker的个数。注意这里是子集合(字母组合集合)，而不是子串。
    int dp[1 << 16];
    int minStickers(vector<string>& stickers, string target) 
    {
        int sz = target.size();
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int state = 0; state < (1 << sz); state++) // 枚举 1 << target.size() 个状态(集合)
        {
            if(dp[state] == - 1) continue;
            for(int i = 0; i < stickers.size(); i++)  // 两个for 枚举 stickers 的每个字符串的每个字母
            {
                int now = state;                       
                for(int j = 0; j < stickers[i].size(); j++)
                {
                    
                    for(int k = 0; k < sz; k++) // 枚举target 的每个字母
                    {
                        if((now >> k) & 1 == 1) continue; // 当前状态(集合)中的 位置 k 已经置为 1， 即已经存在
                        if(stickers[i][j] == target[k])
                        {
                            now |= (1 << k); // 把当前状态(集合)中的位置 k 置为 1，即标志其存在
                            break;
                        }
                    }
                }
                if(dp[now] == -1 || dp[now] > dp[state] + 1)
                {
                    dp[now] = dp[state] + 1;
                }
            }
        }
        return dp[(1 << target.size() ) - 1];
    }
};