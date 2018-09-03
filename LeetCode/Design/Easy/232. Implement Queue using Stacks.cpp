class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>sta1;
    stack<int>sta2;
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sta1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(sta2.empty()) {
            while(!sta1.empty()) {
                int x = sta1.top();
                sta1.pop();
                sta2.push(x);
            }
        }
        int x = sta2.top();
        sta2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while(sta2.empty()) {
            while(!sta1.empty()) {
                int x = sta1.top();
                sta1.pop();
                sta2.push(x);
            }
        }
        int x = sta2.top();
        // sta2.pop();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {   
        if(sta1.empty() && sta2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
