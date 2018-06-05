class Solution {
public:
    //通过重复n1次s1构成S1, 重复n2次s2构成S2, 问你S1里面有多少的S2.
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len = s2.size();
        if(len == 0) return 0;
        vector<int>dp(len,0);
        
        //s1与s2的循环匹配呈现周期性规律，可以通过辅助数组dp进行记录循环节
        for(int i = 0; i < s2.size(); i++)
        {
            int start = i;
            for(auto ch : s1)
            {
                if(ch == s2[start % s2.size()])
                {
                    start++;
                }
            }
            if(start == i) return 0;
            dp[i] = start - i;
           // cout << dp[i] << endl;
        }
        int idx = 0;
        for(int i = 0; i < n1; i++) //重复n1次s1构成S1
        {
            idx += dp[idx % len];
        }
        //算出s2出现的次数，然后除以n2，就可以得出S2出现的次数
        return (idx / len) / n2;
    }
};