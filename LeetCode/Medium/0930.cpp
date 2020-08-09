class Solution {
public:
    // 在一个 0-1 数组 A 里，有多少个非空连续子数组的和是 S
    int numSubarraysWithSum(vector<int>& A, int S) {
        if(A.size() == 0) {
            return 0;
        }
        int sum = 0;
        int ans = 0;
        map<int,int>mp;
        mp[0] = 1;
        // S = P[j] - P[i]，则在 i < j 的范围内，i 的个数即为满足要求的子数组个数
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            if(sum >= S) {
                ans += mp[sum - S];
            }
            mp[sum]++;
        }
        return ans;
    }
};