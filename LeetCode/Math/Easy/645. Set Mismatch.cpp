class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        int dup = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            sum += nums[i];
            if(mp[nums[i]] > 1) {
                dup = nums[i];
            }
        }
        int len = nums.size();
        int miss = len * (len + 1) / 2 - sum + dup;
        // cout << miss << endl;
        return vector<int>({dup,miss});
    }
};