class Solution {
public:
    // O(k*logn)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        if(n == 0 || m == 0) {
            return ans;
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i = 0; i < n; i++) {
            pq.push({ -nums1[i] - nums2[0], {i, 0}});
        }
        k = min(n * m, k);
        while(ans.size() < k) {
            auto cur = pq.top();
            pq.pop();
            int i = cur.second.first;
            int j = cur.second.second;
            ans.push_back({nums1[i], nums2[j]});
            j++;
            if(j < m) {
                pq.push({ -nums1[i] - nums2[j], {i, j}});
            }
        }
        return ans;
    }
};