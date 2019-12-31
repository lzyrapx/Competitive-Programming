/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 17:16:50
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
    // 先序遍历
    vector<int> preorder(Node* root) {
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
            for(int i = (node -> children).size() - 1 ; i >= 0; --i) {
                st.push(node -> children[i]);
            }
        }
        return ans;
    }
};