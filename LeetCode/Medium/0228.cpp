/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-16 23:50:39
 */ 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            int pos = i;
            while(i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) i++;
            if(pos != i) {
                str += "->" + to_string(nums[i]);
            }
            ans.push_back(str);
        }
        return ans;
    }
};