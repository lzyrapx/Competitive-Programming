class Solution {
public:
    /*
    思路：
    用Hash Table来存储sum出现的次数，如果当前位置之前有相加和为sum-k的位置，
    则这两个位置之间的数字相加和为k，以当前位置结尾的相加和为k的子数组个数为
    hash[sum-k]，这样遍历整个数组即可得出满足条件的子数组个数。
    */
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};