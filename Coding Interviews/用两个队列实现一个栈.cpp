class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    queue<int>q;
    queue<int>tmp;
    
    /** Push element x onto stack. */
    void push(int x) {
       while(!q.empty()) {
           tmp.push(q.front());
           q.pop();
       }
        q.push(x);
        while(!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
