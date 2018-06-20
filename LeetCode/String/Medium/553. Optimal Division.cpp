class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size() == 0) return "";
        string ans = to_string(nums[0]);
        if(nums.size() == 1) return ans;
        if(nums.size() == 2) return ans + "/" + to_string(nums[1]);
        else
        {
            for(int i = 1; i < nums.size(); i++) {
                if(i == 1) {
                    ans = ans + "/(" + to_string(nums[i]);
                }
                else {
                    ans = ans + "/" + to_string(nums[i]);
                }
                if(i == nums.size() - 1) ans = ans + ")";
            }
        }
        return ans;
    }
};