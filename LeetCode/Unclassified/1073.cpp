/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 14:42:54
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 14:45:38
 */
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        vector<int> ans;
        int carry = 0;
        int sum = 0;
        while(i >= 0 || j >= 0 || carry != 0) {
            sum = carry;
            sum += (i >= 0)? arr1[i] : 0;
            sum += (j >= 0)? arr2[j] : 0;
            ans.push_back(sum & 1);
            carry = -(sum >> 1); // (sum / 2) is wrong
            i--;
            j--;
        }
        while(ans.size() > 1 && ans.back() == 0) { // no leading zeros
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};