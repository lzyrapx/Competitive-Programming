/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-28 23:24:41
 */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int res = 0;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] != "C" && ops[i] != "D" && ops[i] != "+") {
                st.push(atoi(ops[i].c_str()));
                
            }
            if(ops[i] == "C" && !st.empty()) {
                st.pop();
            }
            if(ops[i] == "D") {
                st.push(2 * st.top());
            }
            if(ops[i] == "+") {
                int l1 = 0, l2 = 0;
                if(!st.empty()) {
                    l1 = st.top();
                    st.pop();
                    if(!st.empty()) {
                        l2 = st.top();
                    }
                    st.push(l1);
                }
                st.push(l1 + l2);
            }
        }
        while(!st.empty()) {
            // cout << st.top() << endl;
            res += st.top();
            st.pop();
        }
        return res;
    }
};