class Solution {
public:
     // turn=1 : player1
    // turn = -1 player2
   int dfs(std::vector<int> &nums,int s,int e,int turn)// [s,e]
   {
     if(s==e) {
       return turn * nums[s];
     }
     int a = turn * nums[s] + dfs(nums,s+1,e,-turn);
     int b = turn * nums[e] + dfs(nums,s,e-1,-turn);
     return turn * max(turn * a, turn * b);
   }
   bool PredictTheWinner(vector<int>& nums) {
     int ans = dfs(nums,0,nums.size()-1,1);
     if(ans >= 0)return 1;
     else return 0;
   }
};