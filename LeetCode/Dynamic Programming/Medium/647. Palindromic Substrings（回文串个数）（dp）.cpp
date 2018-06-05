class Solution {
public:
   int countSubstrings(string s) {
      int sz = s.size();
      std::vector<std::vector<int>> dp(sz+1,std::vector<int>(sz+1,0));
      int cnt = 0;
      for(int end=0;end<sz;end++) {
        dp[end][end] = 1;
        cnt++;
        for(int start=0;start<end;start++) {
          if(s[start] == s[end] && (start + 1 >= end - 1 || dp[start+1][end-1]==1))
          {
            dp[start][end] = 1;
            cnt++;
          }
        }
      }
      return cnt;
    }
};