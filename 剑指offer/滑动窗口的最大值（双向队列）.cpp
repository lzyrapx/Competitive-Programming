class Solution {
public:
    // 时间复杂度O(n)，空间复杂度为O(n)
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>ans;
        if(num.size() == 0) return ans;
        deque<int>que; //双端队列存储num的下标, 队列第一个位置保存当前窗口的最大值
        for(int i = 0; i < (int)num.size(); i++) 
        {
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while(que.size() != 0 && num[que.back()] <= num[i]) que.pop_back();
            
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            while(que.size() != 0 && i + 1 - que.front() > size) que.pop_front();
            
            que.push_back(i); //把每次滑动的num下标加入队列
                
            if(size != 0 && i + 1 >= size) { //当滑动窗口首地址 i 大于等于 size 时才开始写入窗口最大值
                ans.push_back(num[que.front()]);
            }
        }
        return ans;
    }
};