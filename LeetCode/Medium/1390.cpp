class Solution {
public:
    // 做法：O(n*sqrt(n))
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int res = 0;
            int cnt = 0;
            for(int j = 1; j <= sqrt(nums[i]); j++) {
                if(nums[i] % j == 0) {
                    int div = nums[i] / j;
                    if(div != j) {
                        cnt += 2;
                        res += div + j;
                    }
                    else {
                        cnt += 1;
                        res += j;
                    }
                }
            }
            if(cnt == 4) {
                ans += res;
            }
        }
        return ans;
    }
};