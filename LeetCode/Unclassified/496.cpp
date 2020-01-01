/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 23:20:57
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(auto n: nums2) {
            while(st.size() > 0 && st.top() < n) {
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        vector<int>ans;
        for(auto x: nums1) {
            ans.push_back(mp.count(x) ? mp[x]: -1);
        }
        return ans;
    }
};