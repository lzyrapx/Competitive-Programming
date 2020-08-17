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
    // 给定一个 N 叉树，返回其节点值的层序遍历
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root == NULL) {
            return ans;
        }
        queue<Node*>que;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            vector<int>path;
            for(int i = 0; i < sz; i++) {
                Node* cur = que.front();
                que.pop();
                path.push_back(cur -> val);
                for(int j = 0; j < cur -> children.size(); j++) {
                    que.push(cur -> children[j]);
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};