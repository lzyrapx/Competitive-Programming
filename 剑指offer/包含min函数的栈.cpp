class Solution {
    /*
    push: 应用一个辅助栈，压入的时候，如果A栈压入的比B栈压入的大，B栈不压。
    如果A栈压入的小于等于B栈压入的，AB栈同时压入，出栈。
    
    pop: 如果，AB栈顶元素不等，A出，B不出
    */
public:
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
        {
            stack2.push(value);
        }
        // 入栈的元素比stack2中的栈顶元素小或等于则入栈
        if(value <= stack2.top())
        {
            stack2.push(value);
        }
    }
    void pop() {
        if(stack1.top() == stack2.top())
        {
            stack2.pop();
        }
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
    stack<int>stack1;  // 保存数据
    stack<int>stack2; //维护最小值
};