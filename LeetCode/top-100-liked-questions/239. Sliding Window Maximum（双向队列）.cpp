class Solution {
public:
    // 双向队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size() == 0 || k == 0) return ans;
        deque<int>deq; // 用来保存下标
        
        for(int i = 0 ; i < nums.size(); i++) {
            while(!deq.empty() && nums[i] > nums[deq.back()]) deq.pop_back();
            deq.push_back(i);
            if(deq.front() == i - k) deq.pop_front();
            if(i + 1 >= k) {
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};