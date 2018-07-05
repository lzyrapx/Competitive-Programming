
class MinStack {
public:
    // Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    /** initialize your data structure here. */
    // 一个栈维护所有值，一个栈只维护最小值
    MinStack() {
        
    }
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= getMin()) {
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.top() == getMin()) {
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int>s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */