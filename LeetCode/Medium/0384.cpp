class Solution {
public:
    Solution(vector<int>& nums) {
        elements = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return elements;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = elements;
        for(int i = 0; i < ans.size(); i++) {
            int r =  rand() % (i + 1);
            if(r != i) {
                swap(ans[r], ans[i]);
            }
        }
        return ans;
    }
private:
    vector<int>elements;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */