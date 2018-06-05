
// 给你1-n的数 和一个 k , 两个人选数，谁选到总和 为 k 就 谁赢。
class Solution {
public:
     int maxx = 0;
     map<int,int>mp;
     int mask_dp(int desiredTotal, int now)
     {
        if(mp.count(now))return mp[now];
        for(int i=1;i<= maxx;i++)
        {
            if(( now & (1 << i) ) == 0) // (now & (1 << i) == 0 不加括号 WA， 等号优先级比 & 高
            {
                if((desiredTotal <= i)  ||  mask_dp(desiredTotal - i, (1 << i) | now) == 0)
                {
                    mp[now] = 1;
                    return 1;
                }
            }
        }
        mp[now] = 0;
        return 0;
     }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxx = maxChoosableInteger;
        if(maxx >= desiredTotal) return true;
        if((maxx + 1) * maxx / 2  < desiredTotal) return false;
        return mask_dp(desiredTotal,0);
    }
   
    
};