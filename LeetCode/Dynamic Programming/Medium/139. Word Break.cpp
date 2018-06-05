class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        if(wordDict.size()==0) return 0;
        std::vector<int> dp(sz+1,0);
        dp[0] = 1;
        for(int i=1;i<=sz;i++) {
           for(int j=i-1;j>=0;--j) {
             if(dp[j]) {
               string ss = s.substr(j,i-j);
                //for(auto sss : wordDict)
                if(find(wordDict.begin(), wordDict.end(), ss) != wordDict.end())
                {
                  // if(sss == ss) {
                       dp[i] = 1;break;
                  // }
               }
             }
           }
        }
        return dp[sz];
    }
};