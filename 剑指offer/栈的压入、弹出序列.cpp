class Solution {
public:
/*
    
模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
如果不同则继续压栈，直到原数列中所有数字压栈完毕。
检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。
否则，说明出栈队列不能由原数列进行栈操作得到。
*/
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0 && popV.size()==0) return true;
        if(pushV.size()==0) return false;
        if(popV.size()==0) return false;
        if(pushV.size() != popV.size()) return false;
        stack<int>s;
        int j = 0;
        for(int i = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            while( !s.empty() && s.top() == popV[j] ) {
                s.pop();
                j++;
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};