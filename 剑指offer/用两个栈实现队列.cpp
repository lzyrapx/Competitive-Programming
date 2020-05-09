class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int a;
        while(stack2.empty())
        {
            while(!stack1.empty())
            {
                a = stack1.top();
                stack1.pop();
                stack2.push(a);
            }
        }
        a=stack2.top();
        stack2.pop();
        return a;
    }
/*
入队：将元素进栈A
出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
如果不为空，栈B直接出栈。
*/
private:
    stack<int> stack1;
    stack<int> stack2;
};