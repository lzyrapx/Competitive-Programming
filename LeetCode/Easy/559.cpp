/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 16:27:19
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    // 层序遍历
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        queue<Node*>que;
        int dep = 0;
        que.push(root);
        while(!que.empty()) {
            dep++;
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                Node* node = que.front();
                que.pop();
                for(auto child: node -> children) {
                    if(child) {
                        que.push(child);
                    }
                }
            }
        }
        return dep;
    }
};