class Solution {
public:
    // 就是用一个栈来维护递增序列
    // 一直上升就一直push，一旦下降就开始计算，直到遇到比栈里更高的或者栈空再push
    int largestRectangleArea(vector<int>& heights) {
       if(heights.size() == 0) return 0;
        int max_size = 0;
        int idx = 0;
        heights.push_back(0); // 保证正确性
        stack<int>s;
        int n = heights.size();
        while(idx < n)
        {
            if(s.size() == 0 || heights[s.top()] <= heights[idx])
            {
                s.push(idx);
                idx++;
            }
            else
            {
                int curId = s.top(); s.pop();
                int size = 0;
                if(s.size() == 0)
                {
                    size = heights[curId] * idx;
                }
                else {
                    size = heights[curId] * (idx - s.top() - 1);
                    // cout << curId << " " << size << endl;
                }
                if(size > max_size) max_size = size;
            }
        }
        return max_size;
    }
};