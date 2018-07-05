class Solution {
public:
    // nlogk
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        priority_queue<int,vector<int>,greater<int>>que; //从大到小, 最小堆
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) 
        {
            if(nums[i] > que.top())
            {
                que.pop();
                que.push(nums[i]);
            }
        }
        return  que.top();
    }
};