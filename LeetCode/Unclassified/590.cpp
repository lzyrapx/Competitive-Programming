/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 17:49:36
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    // 后序遍历
    vector<int> postorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        if(root == NULL) {
            return ans;
        }
        st.push(root);
        while(!st.empty()) {
            Node* node = st.top();
            st.pop();
            ans.push_back(node -> val);
            for(int i = 0 ; i < (node -> children).size() ; i++) {
                st.push(node -> children[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};