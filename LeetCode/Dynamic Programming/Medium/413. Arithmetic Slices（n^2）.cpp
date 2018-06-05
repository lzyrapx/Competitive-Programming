class Solution {
public:
int numberOfArithmeticSlices(vector<int>& A) {
        // std::vector<std::vector<int>> dp(A.size()+1,std::vector<int> (A.size()+1,0));
        // std::cout << A.size() << '\n';
        // for(int i=0;i<(int)A.size();i++) {
        //   dp[i][i] = 0;
        // }
        int ans = 0;
        // dp[0][0] = dp[0][1] = 0;
        for(int i = 0; i < (int)A.size() - 2; i++){
          int d = A[i+1] - A[i];
          for(int j = i + 2; j < (int)A.size(); j++){
            if(A[j]-A[j-1]==d) {
              ans++;
            }
            else break;
          }

        }
        return ans;
    }
};