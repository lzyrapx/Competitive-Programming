
class Solution {
public:
    int findSubstringInWraproundString(string p) {
     //dp is the maximum unique substring end with ith letter.
      std::vector<int> dp(26, 0);
      int sz = p.size();
      int len = 0;
      for(int i = 0; i < sz; i ++) {
        len = ( i > 0 && (p[i] - p[i-1] == 1) || (p[i] - p[i-1] == -25) ) ? len + 1:1;
        dp[p[i] - 'a'] = max(dp[ p[i] - 'a'] ,len); //比如：如果 "abcd" 是的话, 那么"bcd", "cd" and "d"也是
      }
      int ans = 0;
      for(auto x : dp) {
        ans += x;
      }
      return ans;
  }
};